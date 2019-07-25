Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could 
represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.
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
    void help(TreeNode* root, int &sum, int parent){
        if(!root) return;
        int curr = parent * 10 + root->val;
        if(!root->left && !root->right){
            sum += curr;
        }
        if(root->left) help(root->left, sum, curr);
        if(root->right) help(root->right, sum, curr);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        help(root, sum, 0);
        return sum;
    }
};
