Univalued Binary Tree
 A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

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
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if(root->left != NULL){
            if(root->right != NULL){
                if(root->val == root->left->val && root->val == root->right->val && isUnivalTree(root->left) && isUnivalTree(root->right)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(root->val == root->left->val && isUnivalTree(root->left)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        else{
            if(root->right != NULL){
                if(root->val == root->right->val && isUnivalTree(root->right)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return true;
            }
        }
    }
};
