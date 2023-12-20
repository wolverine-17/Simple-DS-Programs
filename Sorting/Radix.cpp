#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum number to know the number of digits
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(int arr[], int n, int exp)
{
    const int RADIX = 10;
    vector<int> output(n, 0);
    vector<int> count(RADIX, 0);

    // Count the occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % RADIX]++;

    // Accumulate count
    for (int i = 1; i < RADIX; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }

    // Copy the output array to arr[] so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to perform radix sort
void radixSort(int arr[], int n)
{
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
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

    // Perform radix sort
    radixSort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
