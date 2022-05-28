#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *prev;
};

class Doubly_List{
	
	private:
		node *head,*temp,*curr;
		int value;
		
	public:
		
		Doubly_List(){
			head = temp = curr = NULL;
		}
		
		node *createnode(int data){
			node *NewNode=new node;
			NewNode->info=data;
            NewNode->next = NewNode->prev = NULL;
			return NewNode; 
		}
		
		node *gettail(){
			node *iter=head;
			while(iter->next != NULL){
				iter=iter->next;
			}
			return iter;
		} 
		node *search_node(int key){
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
			cout<<"Enter value : "<<endl;
			cin>>value;
			
			if(head == NULL){
                head = createnode(value);
				return;
			}
            
			node *tail=gettail();
			node *newnode=createnode(value);
			newnode->next=NULL;
			newnode->prev=tail;
			tail->next=newnode;
		}

		void Add(){
			int key;
			temp=head;
			if(head==NULL){
				cout<<"List is empty"<<endl;
				return;
			}
			cout<<"after which value you want to add : "<<endl;
			cin>>key;
			node *tail=gettail();
			
			if(key == tail->info){
				temp=tail;
				cout<<"Enter new value : "<<endl;
				cin>>value;
				curr=createnode(value);
				curr->next=NULL;
				curr->prev=temp;
				temp->next=curr;
				return;
			}
			
			while(temp != NULL){
				if(temp->info==key){
					cout<<"Enter new value : "<<endl;
					cin>>value;
					curr=createnode(value);
					curr->next=temp->next;
					curr->prev=temp;
					curr->next->prev=curr;
					temp->next=curr;
					return;
				}
				temp=temp->next;	
			}
		}
		
		void delete_node(){
			temp=head;
			
			if (head == NULL){
				cout<<"List is Empty "<<endl;
				return;
			}
			cout<<"Enter value to delete : "<<endl;
			cin>>value;
			
			node *search=search_node(value);
			node *del = NULL;
			
			if(head == search){
				del=head;
				if(head->next == NULL){
					head=NULL;
					cout<<" now list is empty : "<<endl;
				}
				else{
					head=head->next;
					head->next->prev=head;
					head->prev=NULL;
					delete del;
				}
			}
	
			else {
				del = search;
				temp = search;
				temp=temp->prev;
				
				if(search->next == NULL){
					temp->next=NULL;
				}
				else{
					temp->next=search->next;
					search->next->prev=search->prev;
				}
			}
		}
			
		void print(){
			temp=head;
			while(temp!=NULL){
				cout<<"["<<temp->info<<"]  ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
};

int main(){
	
	int key,num,input;
	Doubly_List obj;
	
	cout<<" Doubly Link List !!! \n "<<endl;
	cout<<"Enter number Nodes "<<endl;
	cin>>num;
	
	for(int i=1;i<=num;i++){
		obj.createList();
	}
	obj.print();
	
	cout<<" press 1 for addition of new node! \n press 2 for deletion! "<<endl;
	cin>>input;
	
	if(input == 1){
		obj.Add();
		obj.print();
	}
	
	if(input == 2){
		obj.delete_node();
		obj.print();
	}
	else {
		cout<<"Wrong input !!! \n ";
	}
	
	return 0;
}
