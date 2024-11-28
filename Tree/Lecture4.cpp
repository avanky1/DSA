// TWO TREES ARE IDENTICAL ( TC: O(N), SC O(N))
// MIRROR TREE
// CHECK FOR BALLANCED TREE
// LEVEL ORDER TRAVERSAL IN SPIRAL FORM
//CHECK IF TWO NODES ARE COUSINS 

// #include <iostream>
// #include <queue>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left, *right;

//     Node(int value)
//     {
//         data = value;
//         left = right = NULL;
//     }
// };

// Node *BinaryTree()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return NULL;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << " ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << " ";
//     temp->right = BinaryTree();
//     return temp;
// }

// bool IsIdentical(Node *r1, Node *r2)
// {
//     if (r1 == NULL && r2 == NULL)
//         return true;
//     if (r1 == NULL || r2 == NULL)
//         return false;
//     if (r1->data != r2->data)
//         return false;
//     return IsIdentical(r1->left, r2->left) && IsIdentical(r1->right, r2->right);
// }

// int main()
// {
//     cout << "Enter the root node of the first tree ";
//     Node *root1 = BinaryTree();

//     cout << "Enter the root node of the second tree ";
//     Node *root2 = BinaryTree();

//     if (IsIdentical(root1, root2))
//         cout << "The trees are identical." << endl;
//     else
//         cout << "The trees are not identical." << endl;

//     return 0;
// }
//<---------------------X--------------------->

// MIRROR TREE

// #include <iostream>
// #include <queue>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left, *right;

//     Node(int value)
//     {
//         data = value;
//         left = right = NULL;
//     }
// };

// Node *BinaryTree()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return NULL;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << " ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << " ";
//     temp->right = BinaryTree();
//     return temp;
// }

// void Mirror(Node *root)
// {
//     if (root == NULL)
//         return;
//     Node *temp = root->right;
//     root->right = root->left;
//     root->left = temp;
//     Mirror(root->left);
//     Mirror(root->right);
// }

// void InOrderTraversal(Node *root)
// {
//     if (root == NULL)
//         return;

//     InOrderTraversal(root->left);
//     cout << root->data << " ";
//     InOrderTraversal(root->right);
// }

// int main()
// {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();

//     cout << "Original tree (In-Order Traversal): ";
//     InOrderTraversal(root);
//     cout << endl;

//     Mirror(root);

//     cout << "Mirrored tree (In-Order Traversal): ";
//     InOrderTraversal(root);
//     cout << endl;

//     return 0;
// }

// void PreOrderTraversal(Node *root)
// {
//     if (root == NULL)
//         return;

//     // Visit the root node
//     cout << root->data << " ";

//     // Recursively traverse the left subtree
//     PreOrderTraversal(root->left);

//     // Recursively traverse the right subtree
//     PreOrderTraversal(root->right);
// }

// int main()
// {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();

//     cout << "Original tree (Pre-Order Traversal): ";
//     PreOrderTraversal(root);
//     cout << endl;

//     Mirror(root);

//     cout << "Mirrored tree (Pre-Order Traversal): ";
//     PreOrderTraversal(root);
//     cout << endl;

//     return 0;
// }

//<------------------X------------------>

// CHECK FOR BALLANCED TREE

// #include <iostream>
// #include <cmath> // For abs() function
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left, *right;

//     Node(int value)
//     {
//         data = value;
//         left = right = NULL;
//     }
// };

// // Function to calculate the height of the tree and check if it is balanced
// int height(Node *root, int &valid)
// {
//     if (root == NULL)
//         return 0;

//     int L = height(root->left, valid);
//     int R = height(root->right, valid);

//     if (abs(L - R) > 1)
//     {
//         valid = 0;
//     }

//     return 1 + max(L, R);
// }

// // Function to check if the tree is balanced
// bool IsBalanced(Node *root)
// {
//     int valid = 1;
//     height(root, valid);
//     return valid;
// }

// // Utility function to create a binary tree
// Node *BinaryTree()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return NULL;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << " ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << " ";
//     temp->right = BinaryTree();
//     return temp;
// }

// int main()
// {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();

//     if (IsBalanced(root))
//         cout << "The tree is balanced." << endl;
//     else
//         cout << "The tree is not balanced." << endl;

//     return 0;
// }

//<-----------------------X---------------------->

// LEVEL ORDER TRAVERSAL IN SPIRAL FORM

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// Function to construct the binary tree based on user input
Node *BinaryTree()
{
    int x;
    cout << "Enter value (-1 for no node): ";
    cin >> x;
    if (x == -1)
        return NULL;

    Node *temp = new Node(x);

    cout << "Enter the left child of " << x << ": ";
    temp->left = BinaryTree();

    cout << "Enter the right child of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

vector<int> LevelOrder(Node *root)
{
    if (root == NULL)
    {
        return {}; // If the tree is empty, return an empty vector.
    }

    stack<Node *> s1; // Stack to hold nodes of the current level (right to left).
    stack<Node *> s2; // Stack to hold nodes of the next level (left to right).
    vector<int> ans;  // Vector to store the final zigzag level order traversal.

    s1.push(root); // Start with the root node in the first stack.

    while (!s1.empty() || !s2.empty())
    {
        
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);

            if (temp->left)
                s2.push(temp->left);
            if (temp->right)
                s2.push(temp->right);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);

            if (temp->right)
                s1.push(temp->right);
            if (temp->left)
                s1.push(temp->left);
        }
    }

    return ans;
}

int main()
{
    cout << "Build the binary tree : " << endl;
    Node *root = BinaryTree();

    vector<int> result = LevelOrder(root);

    // Printing the zigzag level order traversal
    cout << " Level Order Traversal: ";
    for (size_t i = 0; i < result.size(); i++)
    {
        int val = result[i];
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


//CHECK IF TWO ARE COUSINS

