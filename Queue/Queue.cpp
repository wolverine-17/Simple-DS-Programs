#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;
    int choice, value;

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Enqueue
                cout << "Enter value to enqueue: ";
                cin >> value;
                myQueue.push(value);
                cout << value << " enqueued into the queue.\n";
                break;

            case 2:
                // Dequeue
                if (!myQueue.empty()) {
                    value = myQueue.front();
                    myQueue.pop();
                    cout << value << " dequeued from the queue.\n";
                } else {
                    cout << "Queue is empty. Cannot dequeue.\n";
                }
                break;

            case 3:
                // Front
                if (!myQueue.empty()) {
                    value = myQueue.front();
                    cout << "Front element: " << value << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;

            case 4:
                // Size
                cout << "Queue size: " << myQueue.size() << endl;
                break;

            case 5:
                // Display Queue
                if (!myQueue.empty()) {
                    cout << "Queue elements: ";
                    while (!myQueue.empty()) {
                        cout << myQueue.front() << " ";
                        myQueue.pop();
                    }
                    cout << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;

            case 6:
                // Exit
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}
