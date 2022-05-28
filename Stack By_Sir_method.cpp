#include<iostream>
using namespace std;

class stack{
	private:
		int val;
		int *arr;
		int top;
		int size;
	
	public:
		stack(int s){
			size=s;
			top=-1;
			arr=new int[size];
		}
		
		bool isFull(){
			if(top > size-1){
				return true;
			}
			else
			return false;
		}
		
		bool isEmpty(){
			if(top == -1){
				return true;
			}
			else 
			return false;
		}
		
		void push(){
			if(isFull() == true){
				cout<<"stack overflows !!!"<<endl;
				return;
			}
			
			cout<<"Enter inputs "<<endl;
			cin>>val;
			arr[++top] = val;
		}
		
		int pop(){
			
			top=size-1;
			
			int x=arr[top];
			size--;
			top--;
			
			return x;
			
		}
		void print(){
			cout<<"[ ";
			for(int i=0 ;i<size;i++){
				cout<<arr[top];
				if(i < size-1){
					cout<<" , ";
				}
				top--;
			}
			cout<<" ]";
			cout<<endl;
		}
};
int main(){
	
	int x,y;
	
	cout<<"Enter size of stack!!!"<<endl;
	cin>>x;
	
	stack obj(x);
	
	for(int i=0 ; i<x ; i++){
		obj.push();	
	}	
	obj.print();
	
	cout<<"how many times you want to call pop() "<<endl;
	cin>>y;
	
	for(int i=0 ; i<y;i++){
		if(y > x){
			cout<<"Wrong Input!!!"<<endl;
			return 0;
		}
		cout<<obj.pop()<<endl;
		obj.print();
	}
	
	
}
