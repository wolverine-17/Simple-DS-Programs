#include <iostream>

using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid; // Return the index where the key is found
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Return -1 if the key is not found
}

int main()
{
    int n;

    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the sorted elements
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int key;

    // Input the number to search
    cout << "Enter the number to search: ";
    cin >> key;

    // Perform binary search
    int index = binarySearch(arr, 0, n - 1, key);

    // Check if the key is found or not
    if (index != -1)
    {
        cout << "Element " << key << " found at index " << index << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
