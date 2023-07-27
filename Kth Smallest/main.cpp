/**
 * @file kth_smallest.cpp
 * @brief This program finds the kth smallest element in an array using partitioning and recursion functions.
 * @startID qw3581ym
 * @name Nathan Peterson
 * @date 7/6/23
 * @instructor Jei Meichnser
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Swaps two integer values.
 * @param a Pointer to the first value.
 * @param b Pointer to the second value.
 */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Partitions the array.
 * @param arr The array of elements.
 * @param first The index of the first element.
 * @param last The index of the last element.
 * @return The index of the pivot element after partitioning.
 */
int partition(int arr[], int first, int last)
{
    int i = first + 1;
    int pivot = arr[first];

    for (int j = first + 1; j <= last; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i += 1;
        }
    }

    swap(&arr[first], &arr[i - 1]);
    return i - 1;
}

/**
 * @brief Finds the kth smallest element in the array.
 * @param arr The array of elements.
 * @param first The index of the first element.
 * @param last The index of the last element.
 * @param k The kth element to find.
 * @return The kth smallest element in the array.
 */
int ksmall(int arr[], int first, int last, int k)
{
    int pindex;
    if (first < last)
    {
        pindex = partition(arr, first, last);
        if (pindex == k - 1)
        {
            return arr[pindex];
        }
        else if (pindex > k - 1)
        {
            return ksmall(arr, first, pindex - 1, k);
        }
        else
        {
            return ksmall(arr, pindex + 1, last, k);
        }
    }
    else if (first == last && first == k - 1)
    {
        return arr[first];
    }
    // Control reaches here when the partition is not valid
    // or the function reaches the end without a return statement.
    return -1;
}

int main()
{
    int n, i, k, kk;
    int element = 1;
    string s;

    // Get the number of elements in the array
label1:
    cout << "Enter the number of elements in the array (maximum 10): ";
    cin >> n;

   if (n > 0 && n < 11)
    {
        int* arr = new int[n];

        // Get the elements for the array
        for (i = 0; i < n; i++)
        {
            cout << "Enter element " << element << ": ";
            cin >> arr[i];
            element++;
        }

    label2:
        // Ask for the kth smallest integer to find
        cout << "Enter the k for the kth smallest element in the array (1 to " << n << "): ";
        cin >> k;

        if (k < 1 || k > n)
        {
            cout << "Invalid k value. Please enter a value between 1 and " << n << "." << endl;
            goto label2;
        }

        // Get the kth smallest element
        kk = ksmall(arr, 0, n - 1, k);

        // Display the element with the correct syntax
        if (k == 1)
        {
            cout << "The " << k << "st smallest element is: " << kk << endl;
        }
        else if (k == 2)
        {
            cout << "The " << k << "nd smallest element is: " << kk << endl;
        }
        else if (k == 3)
        {
            cout << "The " << k << "rd smallest element is: " << kk << endl;
        }
        else
        {
            cout << "The " << k << "th smallest element is: " << kk << endl;
        }

        // Ask if the user wants to find another k value
        cout << "Do you want to find another k? (y/n): ";
        cin >> s;

        if (s == "y")
        {
            goto label2;
        }
        else
        {
            delete[] arr;  // Free the dynamically allocated memory
            return 0;
        }
    }
    else
    {
        cout << "Invalid input. Please try again!" << endl;
        goto label1;
    }

    return 0;
}
