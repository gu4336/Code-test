vector<int> preorderTraversal(TreeNode* root) {
	vector<int> rec;
	stack<TreeNode*> mystack;
	TreeNode* node = root;
	while(node != NULL || !mystack.empty()){
		while(node != NULL){
			mystack.push(node);
			rec.push_back(node->val);
			node = node->left;
		}
		if(!mystack.empty()){
			node = mystack.top();
			mystack.pop();
			node = node->right; 
		}
	}
	return rec;
}
