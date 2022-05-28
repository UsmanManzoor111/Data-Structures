#include <iostream>
#include <string>
using namespace std;

class list
{
private:
	int *arr;
	int *curr;
	int size;

public:
	list()
	{
		curr = NULL;
	}

	void start()
	{
		curr = arr;
	}

	void tail()
	{
		start();
		for (int i = 0; i < size; i++)
		{
			curr++;
		}
		cout<<i<<endl;
	}

	void next()
	{
		curr++;
	}

	void back()
	{
		curr--;
	}

	void createlist()
	{
		cout << "Enter the size of the array : " << endl;
		cin >> size;
		arr = new int[size];
		start();
		cout << "Enter inputs : " << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> *curr;
			next();
		}
	}
	void print()
	{
		start();
		cout << "Array : "
			 << "[ ";
		for (int j = 0; j < size; j++)
		{
			cout << *curr;
			if (j < size - 1)
			{
				cout << " , ";
			}
			next();
		}
		cout << " ]" << endl;
	}
	void insert(int index, int val)
	{
		if (index < 0)
		{
			cout << "Invalid index: " << endl;
			return;
		}
		size++;
		tail();
		for (int i = size; i >= 0; i--)
		{
			if (i > index)
			{
				*curr = *(curr - 1);
			}
			else if (i == index)
			{
				*curr = val;
			}
			back();
		}
	}
	void remove(int index)
	{
		start();
		for (int i = 1; i <= size; i++)
		{
			if (i >= index)
			{
				*curr = *(curr + 1);
			}
			next();
		}
		size--;
	}
	void update(int index, int val)
	{
		start();
		for (int i = 0; i < size; i++)
		{
			if (i == index)
			{
				*curr = val;
			}
			next();
		}
	}

	bool find(int num)
	{
		curr = arr;
		bool ans = false; //by default we assume the number is not present in an array
		for (int i = 0; i < size; i++)
		{
			if (*curr == num)
			{
				ans = true; //if we it then no need of further ieration
				break;
			}
			curr++;
		}
		return ans;
	}
	void get(int x)
	{
		start();
		for (int i = 0; i < size; i++)
		{
			if (i == x)
			{
				cout << *curr << endl;
			}
			next();
		}
	}
	void length()
	{
		cout << "length = " << size << endl;
	}
	void clear_list()
	{
		start();
		for (int i = 0; i < size; i++)
		{
			delete arr;
			arr++;
		}
	}
};
int main()
{
	int val, index, remove, num, pos, upd_val, upd_index;
	list obj;
	list obj2;
	obj.createlist();
	obj.print();

	//	cout << "Enter index : " << endl;
	//	cin >> index;
	//	cout << "Enter Value : " << endl;
	//	cin >> val;
	//	obj.insert(index, val);
	//	obj.print();
	//
	//	cout << "Enter index to remove: " << endl;
	//	cin >> remove;
	//	obj.remove(remove);
	//	obj.print();
	//
	//	cout << "Enter number to check(find) : " << endl;
	//	cin >> num;
	//	cout << "Answer: " << obj.find(num) << endl;
	//
	//	cout << "Enter Index and we will return value:  " << endl;
	//	cin >> pos;
	//	obj.get(pos);
	//
	//	obj.length();
	//
	//cout<<"Enter value to update : "<<endl;
	//cin>>upd_val;
	//cout<<"Enter index on which you want to update: "<<endl;
	//cin>>upd_index;
	//obj.update(upd_index,upd_val);
	//obj.print();

	//	obj.clear_list();
	//	obj.print();

	//	obj2=obj  // copying array;
	//	obj2.print();

	return 0;
}
