Distribute Coins in Binary Tree
Given the root of a binary tree with N nodes, each node in the tree has node.val coins, 
and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  
(The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

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
    int DFS(TreeNode* root, int &count){
        if(!root) return 0;
        int x = DFS(root->left, count) + DFS(root->right, count);
        x += root->val;
        count += abs(x -1);
        root->val = 1;
        return x - 1;
    }
    int distributeCoins(TreeNode* root) {
        int count = 0;
        DFS(root, count);
        return count;
    }
};
