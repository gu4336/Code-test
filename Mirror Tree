//Given a Binary Tree, convert it into its mirror.

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void mirror(Node* node) 
{
     if(node == NULL) return;
     Node *temp;
     temp = node->right;
     node->right = node->left;
     node->left = temp;
     mirror(node->left);
     mirror(node->right);
}
