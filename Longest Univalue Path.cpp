Longest Univalue Path
Given a binary tree, find the length of the longest path where each node 
in the path has the same value. This path may or may not pass through the root.
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
        int curr = 1;
        if(root->left && root->val == root->left->val){
            if(root->right && root->val == root->right->val){
                curr = max(left, right) + 1;
                m = max(m, left + right);
            }
            else{
                curr = left + 1;
                m = max(m, left);
            }
        }
        else{
            if(root->right && root->val == root->right->val){
                curr = right + 1;
                m = max(m, right);
            }
        }
        
        return curr;
    }
    int longestUnivaluePath(TreeNode* root) {
        int max = 0;
        help(root, max);
        return max;
    }
};
