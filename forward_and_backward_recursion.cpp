#include<iostream>
using namespace std;

class Print_numbers
{
public:
	void row(int num)
	{
		if(num==0)
		{
			return;
		}
		cout<<"forward: "<<num<<endl;
	    row(num-1);
		cout<<"Backward: "<<num<<endl;
	} 
	int sum(int num)
	{
		if(num<=1)
		{
			return num;
		}
		return num+sum(num-1);		
	}	
};
int main()
{
	Print_numbers obj;//int *ptr
	obj.row(5);
	cout<<"sum = "<<obj.sum(6);
		
	return 0;
}

