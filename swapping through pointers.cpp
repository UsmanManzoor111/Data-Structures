#include<iostream>
using namespace std;
class swapping{
	
private:
	
public:
	void swap(int *a,int *b)
	{
		int c;
		c=*a;
		*a=*b;
		*b=c;	
	}
	
};
int main()
{
	int a=9,b=8;
	swapping obj;
	
	cout<<"Numbers before swapping: "<<a<<" , "<<b<<endl;
	obj.swap(&a,&b);
	cout<<"Numbers after swapping: "<<a<<" , "<<b<<endl;
	
	return 0;
}

