#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * 
 */ 
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void inorder(TreeNode* root, vector<int>& nodes) {
        if(!root)
            return;

        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);

        return;
    }

    TreeNode* construct(vector<int>& nodes, int left, int right) {
        if (left < 0 || right >= nodes.size() || left > right)
            return NULL;
        
        int mid = (left + right) / 2 ;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = construct(nodes, left, mid-1);
        root->right = construct(nodes, mid+1, right);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);

        return construct(nodes, 0, nodes.size()-1);
    }
};

int main() {
    return 0;
}