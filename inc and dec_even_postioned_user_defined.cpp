#include<iostream>
using namespace std;

void print(int *arr,int size){
	for(int i=0 ;i<size ;i++){
		cout<<arr[i];
		if(i < size-1){
			cout<<" , ";
		}
	}
	cout<<endl;
}
void Inc_Dec_func(int *arr,int size){
	
	print(&arr[0],size);	
	for(int j=0 ; j<size ; j++){
		if((j+1) % 2 == 0){
			arr[j]++; // is odd
		}
		else
		arr[j]--;  // is even
	}
	print(&arr[0],size);
}

int main(){
	int x=0;
	
	cout<<"Enter size of the array: "<<endl;
	cin>>x;
	int arr[x];
	cout<<"enter inputs!!!"<<endl;
	for(int i=0 ;i<x ;i++){
		cin>>arr[i];
	}
	int length = sizeof(arr)/sizeof(arr[0]);
	
	Inc_Dec_func(&arr[0],length);
	
	return 0;
}
