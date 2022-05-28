#include<bits/stdc++.h>
using namespace std;

class heap
{
private:
    int *h;
    int maxsize;
    int n;

public:
    heap(int *arr, int ms, int sz)
    {
        h = arr;
        maxsize = ms;
        n = sz;
    }
    heap(int size)
    {
        maxsize = size;
        h = new int[maxsize + 1];
        n = 0;
    }

    void insert(int);
    void print();
    void deletemin();
    void heapify(int);
    void bulidheap();
};

void heap::insert(int x)
{
    if (n == maxsize)
    {
        cout << "heap is full : " << endl;
        return;
    }

    n++;
    int i;

    for (i = n; i > 1; i = i / 2)
    {
        if (x >= h[i / 2])
        {
            break;
        }
        h[i] = h[i / 2];
    }
    h[i] = x;
}

void heap ::deletemin()
{
    h[1] = h[n];
    n--;
    heapify(1);
}
void heap ::bulidheap()
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(i);
    }
}

void heap ::heapify(int i)
{
    int change = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if(l <= n && h[l] < h[change]){
        change = l;
    }
    if(r <= n && h[r] < h[change]){
        change = r;
    }

    if(change != i){
        swap(h[i],h[change]);

        heapify(change);
    }
}

// void heap::deletemin()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         h[i] = h[i + 1];
//     }
//     n--;
// }

void heap::print()
{
    cout << "heap : ";
    for (int i = 1; i <= n; i++)
    {
        cout << h[i] << "\t";
    }
    cout << endl;
}
int main()
{

    heap obj(15);
    obj.insert(13);
    obj.insert(14);
    obj.insert(16);
    obj.insert(24);
    obj.insert(21);
    obj.insert(19);
    obj.insert(68);
    obj.insert(85);
    obj.insert(26);
    obj.insert(32);
    obj.insert(31);

    obj.print();
    obj.deletemin();
    obj.print();

    int arr[] = {0, 65, 31, 32, 26, 21, 19, 68, 13, 24, 15, 14, 16, 5, 70, 12};
    int sizeofarr = sizeof(arr) / sizeof(int);
    cout << "Size of array : " << sizeofarr << endl;
    heap obj2(arr, sizeofarr, sizeofarr - 1);
    cout<<"before buildheap :"<<endl; 
    obj2.print();
    cout<<"after buildheap : "<<endl;
    obj2.bulidheap();
    obj2.print();
}