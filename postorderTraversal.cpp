vector<int> postorderTraversal(TreeNode* root) {
	vector<int> rec;
	stack<TreeNode*> mystack;
	TreeNode* node = root;
	TreeNode* lastVisit = root;
	while(node != NULL || !mystack.empty()){
		while(node != NULL){
			mystack.push(node);
			node = node->left;
		}
		node = mystack.top();
		if(node->right == NULL || node->right == lastVisit){
			rec.push_back(node->val);
			mystack.pop();
			lastVisit = node;
			node = NULL;
		}
		else{
			node = node->right;
		}
	}
}
