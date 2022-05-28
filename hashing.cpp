#include <iostream>
using namespace std;

class HashTable
{
private:
    int val, counter, num, newrange, temp;
    int *arr, *curr, *temparr;

public:
    int size, range;
    HashTable()
    {
        size = 500;
        num = 1;
        temp = newrange = 0;
        arr = new int[size];
        this->counter = 0;
        cout << "Enter Range of numbers : " << endl;
        cin >> range;
        while (range > size)
        {
        	cout << "please enter the valid range!!!" << endl;
            cout << "Enter Range of numbers : " << endl;
            cin >> range;
        }

        for (int i = 0; i < range; i++)
        {
            arr[i] = -1;
        }
    }

    bool search(int val)
    {
        int mod = val % range;

        if (arr[mod] == -1)
        {
            return false;
        }
        if (arr[mod] == val)
        {
            return true;
        }
        else
        {
            for (int i = mod + 1; i != mod; i++)
            {
                if (i == range)
                {
                    i = 0;
                }
                if (arr[mod] == val)
                {
                    return true;
                }
                if (arr[mod] == -1)
                {
                    return false;
                }
            }
        }
    }

    void rehashing(int range)
    {
        int value, mod;
        newrange = 2 * range;
        temparr = new int[range];

        for (int i = 0; i < range; i++)
        {
            temparr[i] = arr[i];
        }
        //arr = new int[size];

        for (int i = 0; i < newrange; i++)
        {
            arr[i] = -1;
        }
        for (int i = 0; i < newrange; i++)
        {
            value = temparr[i];
            if (value == -1)
            {
                continue;
            }
            else
            {
                mod = value % newrange;
                if (arr[mod] == -1)
                {
                    arr[mod] = value;
                }
                else
                {
                    for (int i = mod + 1; i != mod; i++)
                    {
                        if (i == newrange)
                        {
                            i = 0;
                        }
                        if (arr[i] == -1)
                        {
                            arr[i] = value;
                            break;
                        }
                    }
                }
            }
        }
    }

    void insertion(int val)
    {
        int mod = val % range;
        counter++;
//
        if (counter >= (range * 70) / 100)
        {
            rehashing(range);
        }

        if (arr[mod] == -1)
        {
            arr[mod] = val;
        }

        else
        {
            for (int i = mod + 1; i != mod; i++)
            {
                if (i == range)
                {
                    i = 0;
                }
                if (arr[i] == -1)
                {
                    arr[i] = val;
                    break;
                }
            }
        }
    }

    void print()
    {
        cout << "HashTable :\t";
        if(newrange != 0){
        	temp = newrange;
		}else{
			temp = range;
		}
        for (int i = 0; i < temp; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};
int main()
{
    int key;
    HashTable obj;

    for(int i=0 ; i< obj.range;i++)
    {
        cout<<"Enter key "<<endl;
        cin>>key;
        obj.insertion(key);
    }
//    obj.insertion(10);
//    obj.insertion(20);
//    obj.insertion(30);
//    obj.insertion(40);
//    obj.insertion(50);
//    obj.insertion(60);
//    obj.insertion(70);
//    obj.insertion(80);
//    obj.insertion(90);
//    obj.insertion(100);
//    obj.insertion(34);
//    obj.insertion(234);
//    obj.insertion(12);
//    obj.insertion(456);
//    obj.insertion(23);
    obj.print();
}
