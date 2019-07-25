Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool help(TreeNode *root, int &height){
		if(root == NULL){
			height = 0;
			return true;
		}
		int height1, height2;
		if(!help(root->left, height1)){
			return false;
		}
		if(!help(root->right, height2)){
			return false;
		}
		height = max(height1, height2) + 1;
		return (height1 - height2 <= 1) && (height2 - height1 <= 1);
	}
    bool isBalanced(TreeNode* root) {
        int height;
        return help(root, height);
    }
};
