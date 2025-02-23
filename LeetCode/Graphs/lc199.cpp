/*
LC 199. Binary Tree Right Side View
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
        vector<int> levelOrder(TreeNode* root){
            vector<int> level;

            queue<TreeNode*> q;
            q.push(root);

            level.push_back(root->val);

            while(!q.empty()){
                int current_size = q.size();

                int value = INT_MAX;
                for(int i = 0; i < current_size; i++){
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left != nullptr){
                        q.push(node->left);
                        value = node->left->val;
                    }

                    if(node->right != nullptr){
                        q.push(node->right);
                        value = node->right->val;
                    }
                }

                if(value != INT_MAX)
                    level.push_back(value);
            }

            return level;
        }

    public:

        vector<int> rightSideView(TreeNode* root) {
            if(root == nullptr)
                return {};

            return levelOrder(root);

        }
};

int main(){
    Solution s;

    return 0;
}   