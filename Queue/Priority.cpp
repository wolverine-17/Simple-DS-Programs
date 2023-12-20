#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> myPriorityQueue;
    int choice, value;

    do
    {
        cout << "\nPriority Queue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Display Priority Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Enqueue
            cout << "Enter value to enqueue: ";
            cin >> value;
            myPriorityQueue.push(value);
            cout << value << " enqueued into the priority queue.\n";
            break;

        case 2:
            // Dequeue
            if (!myPriorityQueue.empty())
            {
                value = myPriorityQueue.top();
                myPriorityQueue.pop();
                cout << value << " dequeued from the priority queue.\n";
            }
            else
            {
                cout << "Priority queue is empty. Cannot dequeue.\n";
            }
            break;

        case 3:
            // Front
            if (!myPriorityQueue.empty())
            {
                value = myPriorityQueue.top();
                cout << "Front element: " << value << endl;
            }
            else
            {
                cout << "Priority queue is empty.\n";
            }
            break;

        case 4:
            // Size
            cout << "Priority queue size: " << myPriorityQueue.size() << endl;
            break;

        case 5:
            // Display Priority Queue
            if (!myPriorityQueue.empty())
            {
                cout << "Priority queue elements (from highest priority to lowest): ";
                while (!myPriorityQueue.empty())
                {
                    cout << myPriorityQueue.top() << " ";
                    myPriorityQueue.pop();
                }
                cout << endl;
            }
            else
            {
                cout << "Priority queue is empty.\n";
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
