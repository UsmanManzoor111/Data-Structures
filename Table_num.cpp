#include<iostream>
using namespace std;

void tableof(int val,int start,int end){
	if(start > end){
		return;
	}
	else
	{
		cout<<val<<" * "<<start<<" = "<<val*start<<endl;
		tableof(val,start+1,end);
	}
}
int main(){
	int x,start,end;
	
	cout<<"Enter Value : "<<endl;
	cin>>x;
	cout<<"Enter starting num : "<<endl;
	cin>>start;
	cout<<"Enter ending num : "<<endl;
	cin>>end;
	
	tableof(x,start,end);
	
	return 0;
}
