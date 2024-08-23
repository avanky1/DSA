#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find the next larger element for each element in the array
//METHOD 1 
vector<long long> nextLargerElement(vector<long long> arr, int n) {
    vector<long long> ans(n, -1);  // Initialize the answer vector with -1
    for(int i = 0; i < n; i++) {   // Iterate over each element
        for(int j = i + 1; j < n; j++) {  // Check elements after the current one
            if(arr[j] > arr[i]) {  // If a larger element is found
                ans[i] = arr[j];   // Update the answer
                break;  // Exit the loop after finding the next larger element
            }
        }
    }
    return ans;  // Return the vector with next larger elements
}

int main() {
    stack<int> myStack;  // Declare a stack of integers
    int n, element;

    // Ask the user for the number of elements
    cout << "Enter the number of elements you want to push onto the stack: ";
    cin >> n;

    vector<long long> arr(n);  // Declare a vector to store the elements

    // Ask the user to input the elements
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; ++i) {
        cin >> element;       // Take input
        arr[i] = element;     // Store in the vector
        myStack.push(element);  // Push the element onto the stack
    }

    // Print elements in the stack
    cout << "\nElements in the stack are:\n";
    while(!myStack.empty()) {  // Loop until the stack is empty
        cout << myStack.top() << " ";  // Print the top element
        myStack.pop();  // Remove the top element
    }
    cout << endl;

    // Call the nextLargerElement function to find the next larger elements
    vector<long long> nextLarger = nextLargerElement(arr, n);

    // Print the next larger elements
    cout << "\nNext larger elements for the input elements are:\n";
    for(int i = 0; i < n; ++i) {
        cout << "Element: " << arr[i] << " -> Next larger: " << nextLarger[i] << endl;
    }

    return 0;
}
