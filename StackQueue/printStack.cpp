#include <iostream>
#include <stack>
using namespace std;


int main() {
    stack<int> myStack;
    int n, element;

    cout << "Enter the number of elements you want to push onto the stack: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; ++i) {
        cin >> element;
        myStack.push(element);
    }

    cout << "\nElements in the stack are:\n";
    while(!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
