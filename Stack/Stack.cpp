#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> myStack;
    int choice, value;

    do
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Is Empty?\n";
        cout << "5. Size\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Push
            cout << "Enter value to push: ";
            cin >> value;
            myStack.push(value);
            cout << value << " pushed onto the stack.\n";
            break;

        case 2:
            // Pop
            if (!myStack.empty())
            {
                value = myStack.top();
                myStack.pop();
                cout << value << " popped from the stack.\n";
            }
            else
            {
                cout << "Stack is empty. Cannot pop.\n";
            }
            break;

        case 3:
            // Peek
            if (!myStack.empty())
            {
                value = myStack.top();
                cout << "Top element: " << value << endl;
            }
            else
            {
                cout << "Stack is empty.\n";
            }
            break;

        case 4:
            // Is Empty
            if (myStack.empty())
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack is not empty.\n";
            }
            break;

        case 5:
            // Size
            cout << "Stack size: " << myStack.size() << endl;
            break;

        case 6:
            // Display Stack
            cout << "Stack elements: ";
            while (!myStack.empty())
            {
                cout << myStack.top() << " ";
                myStack.pop();
            }
            cout << endl;
            break;

        case 7:
            // Exit
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 7);

    return 0;
}
