#include<iostream>
using namespace std;

class stack{
	private:
		int size;
		int top,count;
		int *arr;
		int *curr;
	
	public:
		stack(int s){
			count=0;
			curr = NULL;
			size = s;
			arr=new int[size];
		}
		
		bool isFull(){
			if(count > size){
				return true;
			}
			else
			return false;
		}
		
		bool isEmpty(){
			if(count == 0){
				return true;
			}
			return false;
		}
	
		void push(){
			if(isFull()){
				cout<<"Stack overflow!!!"<<endl;
				return;
			}
			curr = arr;
			cout<<"Enter inputs : "<<endl;
			for(int i=0 ;i<size ;i++){
				cin>>*curr;
				curr++;
				count++;
			}
		}
		
		void pop(){
			if(isEmpty()){
				cout<<"stack underflows !!!"<<endl;
				return;
			}
			curr = arr;
			for (int i=0 ;i<size-1 ;i++){
				curr++;
			}
			int *iter =curr;
			cout<<"pop : "<<*iter<<endl;
			iter = NULL;
			size--;
			count--;
		}
		
		void print(){
			curr = arr;
			cout<<"[ ";
			for(int i=0;i<size ; i++){
				cout<<*curr;
				if(i < size -1 ){
					cout<<" , ";
				}
				curr++;
			}
			cout<<" ]"<<endl;
		}
};
int main(){
	int x,y;
	cout<<"Enter size of stack:"<<endl;
	cin>>x;
	
	stack obj(x);
	
	obj.push();
	obj.print();
	
	cout<<"how many times you want to pop!!!"<<endl;
	cin>>y;
	for(int i=0 ;i<y ;i++){
		if(y>x){
			cout<<y<<" must be less than "<<x<<"!!!!";
			return 0;
		}
		obj.pop();
		obj.print();
	}
}
