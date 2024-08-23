#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;
    int n, element;

    cout << "Enter the number of elements you want to enqueue: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; ++i) {
        cin >> element;
        myQueue.push(element);
    }

    cout << "\nElements in the queue are:\n";
    while(!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    return 0;
}
