/*
LC 1028. Recover a Tree From Preorder Traversal

*/

#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct TreeNode{
    /*
    A binary tree node
    Attributes:
        val: integer value of the node
        left: pointer to the left node
        right: pointer to the right node
    
    Functions:
        Constructors:
            TreeNode(): default constructor
            TreeNode(int x): constructor with value x
            TreeNode(int x, TreeNode* left, TreeNode* right): constructor with value x, left and right pointers
    */
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution{
    public:
        TreeNode* recoverFromPreorder(string s){

            int n = s.size();
            int index = 0;

            stack<TreeNode*> st;

            while(index < n){

                //Find the depth - number of dashes
                int depth = 0;
                while(index < n && s[index] == '-'){
                    depth++;
                    index++;
                }

                //Find the value of the node - look for digits
                int value = 0;
                while(index < n && isdigit(s[index])){
                    value = (value*10) + (s[index] - '0');
                    index++;
                }

                //Create the node
                TreeNode* node = new TreeNode(value);
                
                //Find the correct parent node
                //Pop the nodes from the stack until the size of the stack is less than equal to the depth
                while(st.size() > depth){
                    st.pop();
                }
                
                //If the left child is null, add the node as the left child
                if(!st.empty()){
                    if(st.top()->left == nullptr){
                        st.top()->left = node;
                    }
                    else if(st.top()->right == nullptr){
                        st.top()->right = node;
                    }
                }

                st.push(node);
            }

            while(st.size() > 1){
                st.pop();
            }

            return st.top();
        }

};

int main(){
    Solution s;
    return 0;
}