#include <iostream>

using namespace std;

// Function to perform shell sort
void shellSort(int arr[], int n)
{
    // Start with a large gap and reduce it until the gap becomes 1
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort for elements at each gap
        for (int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            int j;

            // Shift elements that are greater than temp to the right
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            // Place temp in its correct position
            arr[j] = temp;
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

    // Perform shell sort
    shellSort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
