#include<iostream>
#include<cmath>
using namespace std;

int maximal_func(int a[],int length){
	int max = a[0];

	for(int i = 0;i < length;i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
}
int main()
{
	int arr[]={4,5,7,10,1,9};
	int length = sizeof(arr)/sizeof(arr[0]);
	//cout<<"Lenght: "<<length<<endl;
	cout<<"Maximal value is : "<<maximal_func(arr,length)<<endl;
	
	return 0;
}

