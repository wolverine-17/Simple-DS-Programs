#include <iostream>
#include <vector>

using namespace std;

// Function to find the smallest Fibonacci number greater than or equal to n
int findFibonacci(int n)
{
    if (n <= 1)
        return n;

    int fibPrev = 0, fibCurr = 1, fibNext = 1;

    while (fibNext <= n)
    {
        fibPrev = fibCurr;
        fibCurr = fibNext;
        fibNext = fibPrev + fibCurr;
    }

    return fibCurr;
}

// Function to perform Fibonacci search
int fibonacciSearch(int arr[], int n, int key)
{
    int fibPrev = 0;
    int fibCurr = 1;
    int fibNext = fibPrev + fibCurr;

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibNext < n)
    {
        fibPrev = fibCurr;
        fibCurr = fibNext;
        fibNext = fibPrev + fibCurr;
    }

    int offset = -1;

    while (fibNext > 1)
    {
        int i = min(offset + fibPrev, n - 1);

        if (arr[i] == key)
        {
            return i; // Return the index where the key is found
        }
        else if (arr[i] < key)
        {
            fibNext = fibCurr;
            fibCurr = fibPrev;
            fibPrev = fibNext - fibCurr;
            offset = i;
        }
        else
        {
            fibNext = fibPrev;
            fibCurr = fibCurr - fibPrev;
            fibPrev = fibNext - fibCurr;
        }
    }

    if (fibCurr == 1 && arr[offset + 1] == key)
    {
        return offset + 1;
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

    // Perform Fibonacci search
    int index = fibonacciSearch(arr, n, key);

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
