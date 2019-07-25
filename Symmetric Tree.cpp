Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

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
    bool help(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL){
            return root2 == NULL;
        }
        if(root2 == NULL){
            return false;
        }
        if((root1->val == root2->val) && help(root1->left, root2->right) && help(root2->left, root1->right)){
            return true;
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return help(root->left, root->right);
    }
};
