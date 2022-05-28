#include<iostream>
#include<cmath>
using namespace std;

int maximal_func(int *ptr,int length){
	int max = *ptr;

	for(int i = 0;i < length;i++){
		if(max < *ptr){
			max = *ptr; 
		}
		ptr++;
	}
	return max;
}
int minimal_func(int *ptr,int length){
	int min = *ptr;

	for(int i = 0;i < length;i++){
		if(min > *ptr){
			min = *ptr; 
		}
		ptr++;
	}
	return min;
}
int main()
{
	int arr[]={4,5,7,2,1,9};
	int length = sizeof(arr)/sizeof(arr[0]);
	//cout<<"Lenght: "<<length<<endl;
	cout<<"Maximal value is : "<<maximal_func(&arr[0],length)<<endl;
	cout<<"Minimal value is : "<<minimal_func(&arr[0],length)<<endl;

	return 0;
}

