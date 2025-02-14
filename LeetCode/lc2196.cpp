#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{

    // Solution Class to create a binary tree from the given descriptions

    public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions){
        // Function to create a binary tree from the given descriptions
        // Parameters: descriptions: vector<vector<int>> -> 2D vector where each element is a triplet - Parent, Child, Whether the child is left or right child

        unordered_set<int> parents;
        unordered_set<int> children;
        unordered_map<int, vector<pair<int, int>>> parentToChildren;

        for(auto& d : descriptions){
            int parent = d[0], child = d[1], isLeft = d[2];

            parents.insert(parent);
            parents.insert(child);
            children.insert(child);

            parentToChildren[parent].emplace_back(child, isLeft);
        }

        for(auto p  = parents.begin(); p != parents.end(); ){
            if(children.find(*p) != children.end()){
                p = parents.erase(p);
            }
            else{
                p++;
            }
        }

        TreeNode* root = new TreeNode(*parents.begin());

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* parent = q.front();
            q.pop();

            for(auto& c: parentToChildren[parent->val]){
                TreeNode* child = new TreeNode(c.first);

                q.push(child);
                if(c.second){
                    parent->left = child;
                }
                else{
                    parent->right = child;
                }
            }
        }

        return root;
    }
};

void printBinaryTree(TreeNode* root) {
    //Function to print the binary tree using inorder traversal
    //Parameters: root: TreeNode* -> root of the binary tree
    if (root == nullptr) {
        return;
    }

    printBinaryTree(root->left);
    cout << root->val << " ";
    printBinaryTree(root->right);
}

int main(){
    vector<vector<int>> descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};

    Solution s;
    TreeNode* root = s.createBinaryTree(descriptions);

    printBinaryTree(root);
    
    return 0;
}