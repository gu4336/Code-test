Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //计算左右子节点的高度，取小的那个
 //要注意左右子节点是否存在
class Solution {
public:
    void help(TreeNode* root, int &height){
        if(root == NULL){
            height = 0;
            return;
        }
        int h1, h2;
        if(root->left){
            if(root->right){
                help(root->left, h1);
                help(root->right, h2);
                height = min(h1, h2) + 1;
            }
            else{
                help(root->left, h1);
                height = h1 + 1;
            }
        }
        else{
            if(root->right){
                help(root->right, h2);
                height = h2 + 1;
            }
            else{
                height = 1;
            }
        }
    }
    int minDepth(TreeNode* root) {
        int height;
        help(root, height);
        return height;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left){
            if(root->right){
                return min(minDepth(root->left), minDepth(root->right)) + 1;
            }
            else{
                return minDepth(root->left) + 1;
            }
        }
        else{
            if(root->right){
                return minDepth(root->right) + 1;
            }
            else{
                return 1;
            }
        }
    }
};