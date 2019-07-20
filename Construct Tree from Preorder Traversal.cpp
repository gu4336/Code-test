/*Construct Tree from Preorder Traversal
Given an array pre[] that represents Preorder traversal of a binary tree. One more 
array preLN[] is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ 
in preLN[] indicates that the corresponding node in Binary Tree is a leaf node and value
 ‘N’ indicates that the corresponding node is non-leaf node.*/
 
 struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *constructTree(int n, int pre[], char preLN[])
{
    stack<Node*> s;
    Node *temp, *newNode, *root;
    root = new Node();
    root->data = pre[0];
    root->left = root->right = NULL;
    s.push(root);
    for(int i = 1; i < n; i++){
        newNode = new Node();
        newNode->data = pre[i];
        newNode->left = newNode->right = NULL;
        if(!s.empty()){
            temp = s.top();
            if(!temp->left){
                temp->left = newNode;
            }
            else{
                temp->right = newNode;
            }
            if(temp->left && temp->right){
                s.pop();
            }
            if(preLN[i] == 'N'){
                s.push(newNode);
            }
        }
        else{
            s.push(newNode);
        }
    }
    return root;
}