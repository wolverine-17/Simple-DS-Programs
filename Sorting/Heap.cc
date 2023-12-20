#include <iostream>

using namespace std;

// Function to heapify a subtree rooted at index i in the array of size n
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Call heapify on the reduced heap
    }
}

int main()
{
    int n;

    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Perform heap sort
    heapSort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
