Binary Tree Maximum Path Sum
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to 
any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�ݹ����ÿ���ڵ��һ��·�������ֵ������ȫ�����ʱ���õ�ǰ���ֵȥ�Ƚϸýڵ������ߵĺ�
class Solution {
public:
    int help(TreeNode* root, int &m){
        if(!root) return 0;
        int left = help(root->left, m);
        int right = help(root->right, m);
        int ret = max(max(left, right), 0) + root->val;
        m = max(max(m, ret), left + right + root->val);
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int max = root->val;
        help(root, max);
        return max;
    }
};
