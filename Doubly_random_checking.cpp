#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *prev;
};

class Doubly_Ring_List{
	private:
		node *head;
		node *curr;
		node *temp;
		int value;
	public:
		
		Doubly_Ring_List(){
			head=curr=temp=NULL;
		}
		
		node *createNode(int data){
			node *newNode = new node;
			newNode->info=data;
			return newNode;
		}
		
		node *getTail(){
			node *iter = head;
			while(iter->next != head){
				iter=iter->next;		
			}
			return iter;
		}
		
		node *searchNode(int key){
			if(head == NULL){
				cout<<"List is Empty : "<<endl;
				return NULL;
			}
			temp = head;
			while(temp != NULL){
				if(temp->info == key){
					break;
				}
				temp=temp->next;
			}
			return temp;
		}
		
		void createList(){
			cout<<"Enter input : "<<endl;
			cin>>value;
			if(head == NULL){
				head = createNode(value);
				head->next=head;
				head->prev=head;
				return;
			}
			
			node *newNode = createNode(value);
			node *tail = getTail();
			newNode->next=head;
			newNode->prev=tail;
			tail->next=newNode;
			head->prev=newNode;
			
		}
		
		void insert(){
			int key;
			if(head == NULL){
				cout<<"List is Empty!!!"<<endl;
				return;
			}
			
			temp=head;
			
			cout<<"after which value you want a new node!!! "<<endl;
			cin>>key;
			
			do{
				if(temp->info == key){
					if(temp->next == head){
						cout<<"Enter new value : "<<endl;
						cin>>value;
						node *newNode = createNode(value);
						newNode->next=head;
						newNode->prev=temp;
						temp->next=newNode;
						head->prev=newNode;
						head=newNode;
						return;
						
					}
					cout<<"Enter new value : "<<endl;
					cin>>value;
					node *newNode = createNode(value);
					newNode->next=temp->next;
					newNode->prev=temp;
					temp->next=newNode;
					newNode->next->prev=newNode;
					return;
				}
				temp=temp->next;
			}
			while(temp != NULL);
		}
		
	void deletion(){
			temp=head;
			
			if (head == NULL){
				cout<<"List is Empty "<<endl;
				return;
			}
			cout<<"Enter value to delete : "<<endl;
			cin>>value;
			
			node *search=searchNode(value);
			node *del = NULL;
			
			if(head == search){
				del=head;
				if(head->next == head){
					head=NULL;
					cout<<" now list is empty : "<<endl;
					return;
				}
				else{
					head=head->next;
					head->prev=del->prev;
					delete del;
				}
			}
	
			else {
				del = search;
				temp = search;
				temp=temp->prev;
				
				if(search->next == head){
					temp->next=head;
					delete del;
				}
				else{
					temp->next=search->next;
					search->next->prev=search->prev;
				}
			}
		}
	void print(){
			
			if(head == NULL){
				cout<<"List is empty !!!"<<endl;
				return;
			}
			
			temp = head;
			do{
				cout<<" ["<<temp->info<<"] ";
				temp=temp->next;
			}
			while(temp!= head);
			cout<<"\n";
		}	
};
int main(){
	
	Doubly_Ring_List obj;
	
	int x;
	cout<<"Enter number of nodes "<<endl;
	cin>>x;
	for(int i=0;i<x;i++){
		obj.createList();
	}
	obj.print();
	
//	obj.insert();
//	obj.print();
	
	obj.deletion();
	obj.print();
	
}
