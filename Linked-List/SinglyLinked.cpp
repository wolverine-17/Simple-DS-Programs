#include <iostream>

using namespace std;

// Node class for a singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        // Destructor to free the memory used by nodes
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // Function to insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << value << " inserted at the end.\n";
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position. Position should be 1 or greater.\n";
            return;
        }

        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != nullptr; ++i) {
                current = current->next;
            }

            if (current == nullptr) {
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
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from the beginning.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted from the beginning.\n";
    }

    // Function to delete a node at the end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from the end.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }

        cout << "Node deleted from the end.\n";
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (head == nullptr || position < 1) {
            cout << "Invalid operation. List is empty or invalid position.\n";
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != nullptr; ++i) {
                current = current->next;
            }

            if (current == nullptr || current->next == nullptr) {
                cout << "Invalid position. Position exceeds the size of the list.\n";
                return;
            }

            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }

        cout << "Node deleted from position " << position << ".\n";
    }

    // Function to search for an element in the list
    void searchElement(int value) {
        Node* current = head;
        int position = 1;
        bool found = false;

        while (current != nullptr) {
            if (current->data == value) {
                found = true;
                break;
            }
            current = current->next;
            position++;
        }

        if (found) {
            cout << "Element " << value << " found at position " << position << ".\n";
        } else {
            cout << "Element " << value << " not found in the list.\n";
        }
    }

    // Function to display the linked list
    void display() {
        Node* current = head;

        if (current == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    int choice, value, position;

    do {
        cout << "\nLinked List Operations Menu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at a specific position\n";
        cout << "4. Delete at the beginning\n";
        cout << "5. Delete at the end\n";
        cout << "6. Delete at a specific position\n";
        cout << "7. Search for an element\n";
        cout << "8. Display Linked List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Insert at the beginning
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insertAtBeginning(value);
                break;

            case 2:
                // Insert at the end
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insertAtEnd(value);
                break;

            case 3:
                // Insert at a specific position
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                myList.insertAtPosition(value, position);
                break;

            case 4:
                // Delete at the beginning
                myList.deleteAtBeginning();
                break;

            case 5:
                // Delete at the end
                myList.deleteAtEnd();
                break;

            case 6:
                // Delete at a specific position
                cout << "Enter position: ";
                cin >> position;
                myList.deleteAtPosition(position);
                break;

            case 7:
                // Search for an element
                cout << "Enter element to search: ";
                cin >> value;
                myList.searchElement(value);
                break;

            case 8:
                // Display Linked List
                myList.display();
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
