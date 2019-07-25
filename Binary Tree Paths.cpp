Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.
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
    void help(TreeNode* root, vector<string> &result, string curr){
        if(!root) return;
        curr += to_string(root->val);
        if(!root->left && !root->right){
            result.push_back(curr);
            return;
        }
        curr += "->";
        if(root->left) help(root->left, result, curr);
        if(root->right) help(root->right, result, curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string curr;
        help(root, result, curr);
        return result;
    }
};
