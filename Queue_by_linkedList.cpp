#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class queue{
	private:
		int val;
		node *head,*temp;
	public:
		queue(){
			head=NULL;
		}
		
		node *getTail(){
			node *iter = head;
			while(iter->next != NULL){
				iter=iter->next;
			}
			return iter;
		}
		
		node *createNode(int data){
			node *newNode =new node;
			newNode->info=data;
			return newNode;
		}
		
		void enQueue(){
			
			cout<<"Enter input : "<<endl;
			cin>>val;
			
			if(head == NULL){
				head= createNode(val);
				head->next=NULL;
				return;
			}
			node *newNode =createNode(val);
			node *tail =getTail();
			tail->next=newNode;
			newNode->next=NULL;
		}
		
		void print(){
			if(head == NULL){
				cout<<"List is empty!!! "<<endl;
				return;
			}
			temp = head;
			while(temp != NULL){
				cout<<" ["<<temp->info<<"] ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		void deQueue(){
			temp = head;
			node *del = head;
			head=head->next;
			cout<<"deQueue = "<<del->info;
			delete del;
		}
};
int main(){
	int x,y;
	
	queue obj;
	
	cout<<"how many times you want to enQueue() "<<endl;
	cin>>x;
	
	for(int i=0; i<x ;i++){
		obj.enQueue();
	}
	obj.print();
	
	cout<<"How many times you want to dequeue : "<<endl;
	cin>>y;
	
	for(int i=0 ; i<y ; i++){
		if(y > x){
			cout<<"wrong input!!!"<<endl;
			return 0;
		}	
		obj.deQueue();
		obj.print();
	}
}
