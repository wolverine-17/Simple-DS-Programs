#include <iostream>

using namespace std;

// Node class for a doubly linked list
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = next = nullptr;
    }
};

// DoublyLinkedList class
class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    ~DoublyLinkedList()
    {
        // Destructor to free the memory used by nodes
        Node *current = head;
        Node *nextNode;

        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
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
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
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
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
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
            newNode->prev = current;
            if (current->next != nullptr)
            {
                current->next->prev = newNode;
            }
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

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }

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

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }

            if (current->prev != nullptr)
            {
                current->prev->next = nullptr;
            }

            delete current;
        }

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
            Node *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete temp;
        }
        else
        {
            Node *current = head;
            for (int i = 1; i < position - 1 && current != nullptr; ++i)
            {
                current = current->next;
            }

            if (current == nullptr || current->next == nullptr)
            {
                cout << "Invalid position. Position exceeds the size of the list.\n";
                return;
            }

            Node *temp = current->next;
            current->next = current->next->next;

            if (current->next != nullptr)
            {
                current->next->prev = current;
            }

            delete temp;
        }

        cout << "Node deleted from position " << position << ".\n";
    }

    // Function to search for an element in the list
    void searchElement(int value)
    {
        Node *current = head;
        int position = 1;
        bool found = false;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                found = true;
                break;
            }
            current = current->next;
            position++;
        }

        if (found)
        {
            cout << "Element " << value << " found at position " << position << ".\n";
        }
        else
        {
            cout << "Element " << value << " not found in the list.\n";
        }
    }

    // Function to display the doubly linked list
    void display()
    {
        Node *current = head;

        if (current == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "Doubly Linked List: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList myDoublyList;

    int choice, value, position;

    do
    {
        cout << "\nDoubly Linked List Operations Menu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at a specific position\n";
        cout << "4. Delete at the beginning\n";
        cout << "5. Delete at the end\n";
        cout << "6. Delete at a specific position\n";
        cout << "7. Search for an element\n";
        cout << "8. Display Doubly Linked List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Insert at the beginning
            cout << "Enter value to insert: ";
            cin >> value;
            myDoublyList.insertAtBeginning(value);
            break;

        case 2:
            // Insert at the end
            cout << "Enter value to insert: ";
            cin >> value;
            myDoublyList.insertAtEnd(value);
            break;

        case 3:
            // Insert at a specific position
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            myDoublyList.insertAtPosition(value, position);
            break;

        case 4:
            // Delete at the beginning
            myDoublyList.deleteAtBeginning();
            break;

        case 5:
            // Delete at the end
            myDoublyList.deleteAtEnd();
            break;

        case 6:
            // Delete at a specific position
            cout << "Enter position: ";
            cin >> position;
            myDoublyList.deleteAtPosition(position);
            break;

        case 7:
            // Search for an element
            cout << "Enter element to search: ";
            cin >> value;
            myDoublyList.searchElement(value);
            break;

        case 8:
            // Display Doubly Linked List
            myDoublyList.display();
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
