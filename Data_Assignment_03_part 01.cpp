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
		
		void reverse(){
			cout<<"This function reverse the entire list along nodes!!!!"<<endl;
			
			head=gettail();
			temp=head;
			
			while(temp != NULL){
				cout<<" ["<<temp->info<<"] ";
				temp=temp->prev;
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
	
	cout<<" press 1 for reverse() "<<endl;
	cin>>input;
	
	if(input == 1){
		obj.reverse();		
	}
	else{
		cout<<"wrong input!!!";
	}
	
	return 0;
}
