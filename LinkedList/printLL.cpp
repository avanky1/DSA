#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}



int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int n, value;

    cout << "Enter the number of elements you want to add to the linked list: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

        Node *newNode = createNode(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "The elements in the linked list are: ";
    displayList(head);

    

    return 0;
}
