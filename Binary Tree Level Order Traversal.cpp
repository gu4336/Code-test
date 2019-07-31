Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 (ie, from left to right, level by level from leaf to root).

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> myqueue1, myqueue2;
        vector<vector<int>> results;
        if(root == NULL){
            return results;
        }
        myqueue1.push(root);
        while(!myqueue1.empty() || !myqueue2.empty()){
            vector<int> r1;
            while(!myqueue1.empty()){
                TreeNode* temp = myqueue1.front();
                myqueue1.pop();
                r1.push_back(temp->val);

                if(temp->left != NULL){
                    myqueue2.push(temp->left);
                }
                if(temp->right != NULL){
                    myqueue2.push(temp->right);
                }
            }
            if(r1.size() > 0){
                results.push_back(r1);
            }
            
            vector<int> r2;
            while(!myqueue2.empty()){
                TreeNode* temp = myqueue2.front();
                myqueue2.pop();
                r2.push_back(temp->val);

                if(temp->left != NULL){
                    myqueue1.push(temp->left);
                }
                if(temp->right != NULL){
                    myqueue1.push(temp->right);
                }
            }
            if(r2.size() > 0){
                results.push_back(r2);
            }
        }
        
        vector<vector<int>> results2;
        int n = results.size();
        for(int i = n - 1; i >= 0; i--){
            int m = results[i].size();
            vector<int> r;
            for(int j = 0; j < m; j++){
                r.push_back(results[i][j]);
            }
            results2.push_back(r);
        }
        return results2;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front(); q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};
