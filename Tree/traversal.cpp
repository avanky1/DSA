// BST TRAVERSAL 
//(TC: n, SC: height of tree)

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
//PRE ORDER
//IN ORDER
//POST ORDER
void PreOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    PreOrder(root->left);
    PreOrder(root->right);
}

void Inorder(Node *root){
    if(root==NULL)
    return;

    Inorder(root->left);
    cout<<root->data;
    Inorder(root->right);
}

void PostOrder(Node *root){
    if(root==NULL)
    return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data;
}


Node *BinaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    cout << "Enter the left child of " << x << " ";
    temp->left = BinaryTree();

    cout << "Enter the right child of " << x << " ";
    temp->right = BinaryTree();
    return temp;
}
int main()
{
    cout << "Enter the root node ";
    Node *root;
    root = BinaryTree();

    //pre
    cout<<"\npreorder ";
    PreOrder(root);

    cout<<"\nInorder ";
    Inorder(root);

    cout<<"\npostorder ";
    PostOrder(root);
}



