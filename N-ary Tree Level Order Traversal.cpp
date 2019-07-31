N-ary Tree Level Order Traversal
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> myqueue;
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        myqueue.push(root);
        while(!myqueue.empty()){
            int n = myqueue.size();
            vector<int> r;
            for(int i = 0; i < n; i++){
                Node *temp = myqueue.front();
                myqueue.pop();
                r.push_back(temp->val);
                int m = temp->children.size();
                for(int j = 0; j < m; j++){
                    myqueue.push(temp->children[j]);
                }
            }
            result.push_back(r);
        }
        return result;
    }
};
