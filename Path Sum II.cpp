Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.



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
    void help(TreeNode* root, int sum, vector<vector<int>> &result, vector<int> temp){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val == sum){
            result.push_back(temp);
            return;
        }
        help(root->left, sum - root->val, result, temp);
        help(root->right, sum - root->val, result, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        if(!root) return result;
        help(root, sum, result, temp);
        return result;
    }
};
