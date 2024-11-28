#include <iostream>
#include <queue>
// using namespace std;

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

int main()
{
    int x;
    cout << "Enter the root value :";
    cin >> x;
    int first, second;
    queue<Node *> q;
    Node *root = new Node(x);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop(); 
        cout << "Enter the left child value " << temp->data << " : ";
        cin >> first; // left node ki value
        if (first != -1)
        {
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cout << "Enter the right child value " << temp->data << " : ";
        cin >> second;
        if (second != -1)
        {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
}