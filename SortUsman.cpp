#include <bits/stdc++.h>
using namespace std;

void selection_sort(int *ptr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i; j < size - 1; j++)
        {
            if (ptr[min] > ptr[j + 1])
            {
                min = j + 1;
            }
        }
        swap(ptr[min], ptr[i]);
    }
}

void bubble_sort(int *ptr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - i); j++)
        {
            if (ptr[j - 1] > ptr[j])
            {
                swap(ptr[j - 1], ptr[j]);
            }
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    //insertion from array
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[i + l];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j <= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int linearSearch(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return 1;
        }
    }
    return 0;
}

int binarySearch(int arr[], int l, int r, int val)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == val)
        {
            return 1;
        }

        if (arr[mid] < val)
        {
            return binarySearch(arr, mid + 1, r, val);
        }
        else
        {
            return binarySearch(arr, l, mid - 1, val);
        }
    }
    return 0;
}
void print(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[] = {21, 33, 67, 84, 49, 50, 75, 15};
    int size_arr = sizeof(arr) / sizeof(int);

    print(arr, size_arr);

    cout << "selection sort \t";
    selection_sort(arr, size_arr);
    print(arr, size_arr);

    cout << "bubble sort \t";
    bubble_sort(arr, size_arr);
    print(arr, size_arr);

    cout << "Merge sort \t";
    merge_sort(arr, 0, size_arr - 1);
    print(arr, size_arr);

    cout << "Quick Sort \t";
    quickSort(arr, 0, size_arr);
    print(arr, size_arr);

    cout << "Insertion Sort \t";
    insertionSort(arr, size_arr);
    print(arr, size_arr);

    cout << "linear search \t" << linearSearch(arr, size_arr, 75) << endl;

    cout << "Binary Search \t" << binarySearch(arr, 0, size_arr - 1, 50) << endl;

    return 0;
}