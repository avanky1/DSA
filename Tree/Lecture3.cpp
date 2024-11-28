// LEVEL ORDER TRAVERSAL
// SIZE OF BINARY TREE
// SUM OF NODES
// COUNT LEAF NODE
//COUNT NON LEAF NODE
//HEIGHT OF BT



#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

Node *BinaryTree()
{
    int x;
    cin >> x;
    if (x == -1)
        return nullptr;

    Node *temp = new Node(x);

    cout << "Enter the left child of " << x << ": ";
    temp->left = BinaryTree();

    cout << "Enter the right child of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

//LEVEL ORDER TRAVERSAL

vector<int> levelOrder(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    return ans;
}

int main()
{
    cout << "Enter the root node: ";
    Node *root = BinaryTree();

    // Perform level order traversal and print the result
    vector<int> result = levelOrder(root);

    cout << "Level order traversal: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

//<-----------------------------X------------------------->


// SIZE OF BT
//  #include <iostream>
//  using namespace std;

// class Node {
// public:
//     int data;
//     Node *left, *right;

//     Node(int value) {
//         data = value;
//         left = right = nullptr;
//     }
// };

// Node *BinaryTree() {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return nullptr;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << ": ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << ": ";
//     temp->right = BinaryTree();

//     return temp;
// }

//1st method
// void Total(Node *root, int &count) {
//     if (root == nullptr)
//         return;
//     count++;
//     Total(root->left, count);
//     Total(root->right, count);
// }

//2nd method

// int Total(Node *root) {
//     if (root == nullptr)
//         return 0;

//     return 1 + Total(root->left) + Total(root->right);
// }
// int main() {
//     Node *root = BinaryTree();
//     int count = Total(root);
//     cout << "Total number of nodes: " << count << endl;
//     return 0;
// }

// int main() {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();
//     int count = 0;
//     Total(root, count);
//     cout << "Total number of nodes: " << count << endl;
//     return 0;
// }

//<-----------------------------X------------------------->


// SUM OF BT
// #include <iostream>
// using namespace std;

// class Node
// {
// public: 
//     int data;
//     Node *left, *right;

//     Node(int value)
//     {
//         data = value;
//         left = right = nullptr;
//     }
// };

// Node *BinaryTree()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return nullptr;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << ": ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << ": ";
//     temp->right = BinaryTree();

//     return temp;
// }

// void TotalSum(Node *root, int &sum)
// {
//     if (root == NULL)
//         return;

//     sum += root->data;
//     TotalSum(root->left, sum);
//     TotalSum(root->right, sum);
// }

// int Totalsum(Node *root){
//     if(root==NULL)
//     return 0;

//     return root->data+ Totalsum(root->left)+ Totalsum(root->right);
// }
// int main() {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();
//     int sum = Totalsum(root);
//     cout << "Total sum: " << sum << endl;
// }

// int main()
// {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();
//     int sum = 0;
//     TotalSum(root, sum);
//     cout << "Total sum :" << sum << endl;
// }

//<-----------------------------X------------------------->


// COUNT LEAF NODE

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left, *right;

//     Node(int value)
//     {
//         data = value;
//         left = right = nullptr;
//     }
// };

// Node *BinaryTree()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return nullptr;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << ": ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << ": ";
//     temp->right = BinaryTree();

//     return temp;
// }

// void CountLeaf(Node *root, int &count)
// {
//     if (root == NULL)
//         return;
//     if (!root->left && !root->right)
//     {
//         count++;
//         return;
//     }
//     CountLeaf(root->left, count);
//     CountLeaf(root->right, count);
// }

// int main()
// {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();
//     int count = 0;
//     CountLeaf(root, count);
//     cout << "Total sum :" << count << endl;
// }

//<-----------------------------X------------------------->



//COUNT NON LEAF NODE

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left, *right;

//     Node(int value)
//     {
//         data = value;
//         left = right = nullptr;
//     }
// };

// Node *BinaryTree()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return nullptr;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << ": ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << ": ";
//     temp->right = BinaryTree();

//     return temp;
// }

// int CountNonLeaf(Node *root){
//     if(root==nullptr){
//         return 0;
//     }

//     if(!root->left && !root->right)
//     return 0;
//     return (1+ CountNonLeaf(root->left) + CountNonLeaf(root->right));
// }
// int main()
// {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();
    
//     int count = CountNonLeaf(root);
//     cout << "Total number of non-leaf nodes: " << count << endl;
//     return 0;
// }

//<-----------------------------X--------------------------->


//HEIGHT OF BT

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left, *right;

//     Node(int value)
//     {
//         data = value;
//         left = right = nullptr;
//     }
// };

// Node *BinaryTree()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return nullptr;

//     Node *temp = new Node(x);

//     cout << "Enter the left child of " << x << ": ";
//     temp->left = BinaryTree();

//     cout << "Enter the right child of " << x << ": ";
//     temp->right = BinaryTree();

//     return temp;
// }


// int CalculateHeight(Node *root) {
//     if(root == NULL) {
//         return -1;
//     }

//     int leftHeight = CalculateHeight(root->left);
//     int rightHeight = CalculateHeight(root->right);

//     return 1 + max(leftHeight, rightHeight);
// }

// int main()
// {
//     cout << "Enter the root node: ";
//     Node *root = BinaryTree();
    
//     int height = CalculateHeight(root);
    
//     cout << "Height of the binary tree: " << height << endl;

//     return 0;
// }

//<-----------------------------X------------------------->
