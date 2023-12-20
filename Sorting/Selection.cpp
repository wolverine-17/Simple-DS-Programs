#include <iostream>

using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
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

    // Perform selection sort
    selectionSort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
