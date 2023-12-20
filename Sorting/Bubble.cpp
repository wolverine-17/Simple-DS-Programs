#include <iostream>

using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        // Last i elements are already in place, so no need to check them
        for (int j = 0; j < n - i - 1; ++j)
        {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    // Perform bubble sort
    bubbleSort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
