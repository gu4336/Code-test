Vertical Order Traversal of a Binary Tree
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be 
at positions (X-1, Y-1) and (X+1, Y-1).

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        map<int, vector<int>> mymap;
        queue<pair<int, TreeNode*>> myqueue;
        myqueue.push({0, root});
        while(!myqueue.empty()){
            auto temp = myqueue.front();
            myqueue.pop();
            mymap[temp.first].push_back(temp.second->val);
            if(temp.second->left) myqueue.push({temp.first - 1, temp.second->left});
            if(temp.second->right) myqueue.push({temp.first + 1, temp.second->right});
        }
        for(auto a : mymap){
            result.push_back(a.second);
        }
        return result;
    }
};