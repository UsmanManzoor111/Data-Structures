#include<iostream>
using namespace std;

class queue{
	public:
		int *arr;
		int val;
		int top,size,front,rear,num;
		
		queue(int s){
			size=s;
			front=0;
			rear=-1;
			arr=new int[size];
		}
		
		bool isFull(){
			if(num == size){
				return true;
			}
			else
				return false;
		}
		
		bool isEmpty(){
			if( num == 0){
				return true;
			}
			else
				return false;
		}
		
		void enQueue(){
			if(isFull()){
				cout<<"Queue Overflows!!! "<<endl;
				return;
			}
			if(rear == size-1){
				rear=-1;
			}
			if(rear == front && isFull()){
				cout<<"queue is FULL!!!"<<endl;
				return;
			}
			cout<<"Enter inputs "<<endl;
			cin>>val;
	
			num++;
			arr[++rear]=val;
		}
		
		int deQueue(){
			if(isEmpty()){
				cout<<"Queue Underflows!!! "<<endl;
				return 0;
			}
			if(front == size-1){
				front =0;	
			}
			if(front == rear && isEmpty()){
				cout<<"queue is Empty !!!"<<endl;
				return 0; 
			} 
			val = arr[front];
			front++;
			
			num--;
			
			return val;	
		}
		
		void print(){
			top = front;
			
			cout<<" [";
			for(int i=0 ; i<=num ; i++){
				if(top > rear){
					top = 0;
				}
				cout<<arr[top];
				if(i != num ){
					cout<<" , ";
				}
				top++;
			}
			cout<<" ]"<<endl;
		}
		
};
int main(){
	int x,y,input;
	char choice;
	
	cout<<"Enter the size of the queue : "<<endl;
	cin>>x;

	queue obj(x);
	cout<<"start "<<endl;
	cout<<"front = "<<obj.front<<endl;
	cout<<"rear = "<<obj.rear<<endl;
	
	do{	
	cout<<"how many times you want to enqueue "<<endl;
	cin>>input;
	for(int i=0 ; i<input ; i++){
		obj.enQueue();	
	}
	obj.print();
	cout<<"front = "<<obj.front<<endl;
	cout<<"rear = "<<obj.rear<<endl;
	
		cout<<"How many times you want to dequeue : "<<endl;
		cin>>y;
	
		for(int i=0 ; i<y ; i++){
			if(y > x){
				cout<<"wrong input!!!"<<endl;
				return 0;
			}	
			cout<<"deQueue element = "<<obj.deQueue();
			obj.print();
		}
		cout<<"front = "<<obj.front<<endl;
		cout<<"rear = "<<obj.rear<<endl;
		cout<<"want to continue? y/n "<<endl;
		cin>>choice;
	}
	while(choice != 'n');  
}
