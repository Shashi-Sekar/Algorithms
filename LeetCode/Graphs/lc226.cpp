/*
LC 226. Invert Binary Tree

*/

#include<iostream>
#include<stack>

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
        TreeNode* invertTree(TreeNode* root){
            if(root == nullptr)
                return root;

            stack<TreeNode*> st;
            st.push(root);

            while(!st.empty()){
                TreeNode* current = st.top();
                st.pop();

                TreeNode* temp = current->left;
                current->left = current->right;
                current->right = temp;

                if(current->left != nullptr)
                    st.push(current->left);
                if(current->right != nullptr)
                    st.push(current->right);
            }
        }
};

int main(){
    Solution s;

    return 0;
}