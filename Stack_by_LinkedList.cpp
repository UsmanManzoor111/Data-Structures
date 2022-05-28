#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};
class stack{
	private:
		node *head;
		node *temp;
		int val;
		
	public:
		stack(){
			head=NULL;
		}
		
		node *createNode(int data){
			node *newNode = new node;
			newNode->info=data;
			return newNode;
		}
		
		node *getTail(){
			node *iter = head;
			while(iter->next != NULL){
				iter=iter->next;
			}
			return iter;
		}
		
		void push(){
			cout<<"Enter value for stack!!!!"<<endl;
			cin>>val;
			
			if(head == NULL){
				head=createNode(val);
				head->next=NULL;
				return;
			}
			
			node *newNode=createNode(val);
			newNode->next=head;
			head=newNode;
		}
		
		void pop(){
			if(head == NULL){
				cout<<"stack underflows "<<endl;
				return;
			}
			cout<<" pop() = "<<head->info<<endl;
			node *del = head;
			head = head->next;
			delete del; 
			
			
		}
		node *top(){
			return head;
		}
		
		void print(){
			
			if(head == NULL){
				cout<<" Stack is Empty!!!"<<endl;
				return;
			}
			temp = head;
			
			while(temp != NULL){
				cout<<" ["<<temp->info<<"] ";
				temp=temp->next;	
			}
			cout<<endl;
		}
		
};
int main(){
	int x,y;
	stack obj;
	
	cout<<"How many times you want to push() "<<endl;
	cin>>x;
	
	for(int i=0 ; i<x ; i++){
		obj.push();
	}
	obj.print();
	
	cout<<"how many times you want to pop() "<<endl;
	cin>>y;
	
	for(int i=0 ; i<y ; i++){
		if(x < y){
			cout<<" you can not "<<y<<" times !!! b/c push is less than pop "<<endl;
			break;
		}
		obj.pop();
	}	
	obj.print();
}
