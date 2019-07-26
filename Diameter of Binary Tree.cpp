Diameter of Binary Tree
 Given a binary tree, you need to compute the length of the diameter of the tree. 
 The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
 This path may or may not pass through the root.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int help(TreeNode* root, int &m){
        if(!root) return 0;
        int left = help(root->left, m);
        int right = help(root->right, m);
        int curr = max(left, right) + 1;
        m = max(m, left + right);
        return curr;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        help(root, max);
        return max;
    }
};
