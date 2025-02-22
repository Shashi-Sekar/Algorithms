/*
LC 102. Binary Tree Level Order Traversal
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    /*
    A binary tree node
    Attributes:
        val: integer value of the node
        left: pointer to the left node
        right: pointer to the right node
    */
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution{
    public:
        vector<vector<int>> levelOrder(TreeNode* root){
            vector<vector<int>> levels;
            
            if(root == nullptr)
                return levels;

            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()){

                //Number of nodes in the current level
                int level_size = q.size();
                vector<int> level;

                for(int i = 0; i < level_size; i++){
                    TreeNode* current = q.front();
                    q.pop();

                    level.push_back(current->val);

                    if(current->left != nullptr)
                        q.push(current->left);

                    if(current->right != nullptr)
                        q.push(current->right);
                }

                levels.push_back(level);
            }

            return levels;
        }
};

int main(){
    Solution s;
    return 0;
}