#include<iostream>
using namespace std;

void add_new_chunk_in_array(int array[],int &size)
{
	size++;
	int num,index;
	cout<<"Enter number as a input: "<<endl;
	cin>>num;
	cout<<"Enter index at which you want to insert: "<<endl;
	cin>>index;
	
	for(int i=size;i>0;i--)
	{
		if(index==i)
		{
			array[i]=num;
			break;
		}
		if(index<i)
		{
			array[i]=array[i-1];
		}
	}
}
void print_array(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" , ";
	}
	cout<<endl;
}
int main()
{
	int array[]={1,2,3,4};
	int length=sizeof(array)/sizeof(array[0]);
	cout<<"before: ";
	print_array(array,length);
	add_new_chunk_in_array(array,length);
	cout<<"after: ";
	print_array(array,length);
	return 0;
}

