#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front, rear, capacity, size;

public:
    CircularQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        size++;

        cout << value << " enqueued into the circular queue.\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        int value = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }

        size--;

        cout << value << " dequeued from the circular queue.\n";
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }

        return arr[front];
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);

        cout << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue myCircularQueue(capacity);

    int choice, value;

    do
    {
        cout << "\nCircular Queue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Display Circular Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Enqueue
            cout << "Enter value to enqueue: ";
            cin >> value;
            myCircularQueue.enqueue(value);
            break;

        case 2:
            // Dequeue
            myCircularQueue.dequeue();
            break;

        case 3:
            // Front
            cout << "Front element: " << myCircularQueue.getFront() << endl;
            break;

        case 4:
            // Size
            cout << "Circular queue size: " << myCircularQueue.getSize() << endl;
            break;

        case 5:
            // Display Circular Queue
            myCircularQueue.display();
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
