#include <bits/stdc++.h>
using namespace std;

void asc_order(int *ptr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (ptr[i] > ptr[j])
            {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

void dsc_order(int *ptr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (ptr[i] < ptr[j])
            {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}
void print(int *x, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << x[i] << "\t";
    }
}
int main()
{
    int arr[] = {12, 13, 2, 1, 14, 56, 22};
    int sizeOfArray = sizeof(arr) / sizeof(int);

    cout << "Asc Order = ";
    asc_order(arr, sizeOfArray);
    print(arr, sizeOfArray);
    cout << endl;
    cout << "Dsc Order = ";
    dsc_order(arr, sizeOfArray);
    print(arr, sizeOfArray);
}