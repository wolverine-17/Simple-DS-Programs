#include <iostream>

using namespace std;

// Node class for a circular linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// CircularLinkedList class
class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    ~CircularLinkedList()
    {
        // Destructor to free the memory used by nodes
        if (head == nullptr)
        {
            return;
        }

        Node *current = head->next;
        while (current != head)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete head;
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }

            newNode->next = head;
            head = newNode;
            last->next = newNode;
        }

        cout << value << " inserted at the beginning.\n";
    }

    // Function to insert a node at the end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }

            last->next = newNode;
            newNode->next = head;
        }

        cout << value << " inserted at the end.\n";
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position. Position should be 1 or greater.\n";
            return;
        }

        Node *newNode = new Node(value);

        if (position == 1)
        {
            if (head == nullptr)
            {
                head = newNode;
                newNode->next = head;
            }
            else
            {
                Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }

                newNode->next = head;
                head = newNode;
                last->next = newNode;
            }
        }
        else
        {
            Node *current = head;
            for (int i = 1; i < position - 1 && current != nullptr; ++i)
            {
                current = current->next;
            }

            if (current == nullptr)
            {
                cout << "Invalid position. Position exceeds the size of the list.\n";
                delete newNode;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        cout << value << " inserted at position " << position << ".\n";
    }

    // Function to delete a node at the beginning
    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete from the beginning.\n";
            return;
        }

        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        Node *temp = head;
        head = head->next;
        last->next = head;
        delete temp;

        cout << "Node deleted from the beginning.\n";
    }

    // Function to delete a node at the end
    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete from the end.\n";
            return;
        }

        Node *last = head;
        Node *prev = nullptr;

        while (last->next != head)
        {
            prev = last;
            last = last->next;
        }

        if (prev != nullptr)
        {
            prev->next = head;
        }
        else
        {
            head = nullptr;
        }

        delete last;

        cout << "Node deleted from the end.\n";
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position)
    {
        if (head == nullptr || position < 1)
        {
            cout << "Invalid operation. List is empty or invalid position.\n";
            return;
        }

        if (position == 1)
        {
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }

            Node *temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }
        else
        {
            Node *current = head;
            Node *prev = nullptr;

            for (int i = 1; i < position && current->next != head; ++i)
            {
                prev = current;
                current = current->next;
            }

            if (current == head)
            {
                cout << "Invalid position. Position exceeds the size of the list.\n";
                return;
            }

            prev->next = current->next;
            delete current;
        }

        cout << "Node deleted from position " << position << ".\n";
    }

    // Function to search for an element in the list
    void searchElement(int value)
    {
        Node *current = head;
        int position = 1;
        bool found = false;

        do
        {
            if (current->data == value)
            {
                found = true;
                break;
            }
            current = current->next;
            position++;
        } while (current != head);

        if (found)
        {
            cout << "Element " << value << " found at position " << position << ".\n";
        }
        else
        {
            cout << "Element " << value << " not found in the list.\n";
        }
    }

    // Function to display the circular linked list
    void display()
    {
        Node *current = head;

        if (current == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "Circular Linked List: ";
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main()
{
    CircularLinkedList myCircularList;

    int choice, value, position;

    do
    {
        cout << "\nCircular Linked List Operations Menu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at a specific position\n";
        cout << "4. Delete at the beginning\n";
        cout << "5. Delete at the end\n";
        cout << "6. Delete at a specific position\n";
        cout << "7. Search for an element\n";
        cout << "8. Display Circular Linked List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Insert at the beginning
            cout << "Enter value to insert: ";
            cin >> value;
            myCircularList.insertAtBeginning(value);
            break;

        case 2:
            // Insert at the end
            cout << "Enter value to insert: ";
            cin >> value;
            myCircularList.insertAtEnd(value);
            break;

        case 3:
            // Insert at a specific position
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            myCircularList.insertAtPosition(value, position);
            break;

        case 4:
            // Delete at the beginning
            myCircularList.deleteAtBeginning();
            break;

        case 5:
            // Delete at the end
            myCircularList.deleteAtEnd();
            break;

        case 6:
            // Delete at a specific position
            cout << "Enter position: ";
            cin >> position;
            myCircularList.deleteAtPosition(position);
            break;

        case 7:
            // Search for an element
            cout << "Enter element to search: ";
            cin >> value;
            myCircularList.searchElement(value);
            break;

        case 8:
            // Display Circular Linked List
            myCircularList.display();
            break;

        case 9:
            // Exit
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 9);

    return 0;
}
