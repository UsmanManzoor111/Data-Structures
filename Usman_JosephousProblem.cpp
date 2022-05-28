#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *prev;
};

class JosProb{
	private:
		node *head;
		node *curr;
		node *temp;
		int value;
	public:
		JosProb(){
			head = NULL;
		}
		
		node *createNode(int key){
			node *newNode=new node;
			newNode->info=key;
			return newNode;
		}
		
		node *searchNode(int data){
			if(head == NULL){
				cout<<"List is Empty!!!"<<endl;
				return head;
			}
			 
			node *iter=head;
			do{
				if(iter->info == data){
					break;
				}
				iter=iter->next;
			}
			while(iter != head);
			return iter;
		}
		
		node *getTail(){
			node *iter = head;
			while(iter->next != head){
				iter=iter->next;
			}
			return iter;
		}
		
		void createList(){
			cout<<"Enter value "<<endl;
			cin>>value;
			
			if(head == NULL){
				head=createNode(value);
				head->next=head;
				head->prev=head;
				return;
			}
			node *newNode=createNode(value);			
			node *tail=getTail();
			
			newNode->prev=tail;
			newNode->next=head;
			tail->next=newNode;
			head->prev=newNode;
		}
		
		void JProb(){
			
			curr = head;
			node *del = head->next;
			while(head->next != head){
				for(int i=1; i<3; i++){
					curr=curr->next;
					del=del->next;
				}
				curr->next=del->next;
				del->next->prev=curr;
				
				if(del == head){
					head = head->next;
					head->prev->prev->next=head;
				}
				
				cout<<del->info<<" killed "<<endl;
				delete del;
				curr=curr->next;
				del=curr->next;
			}
			cout<<"kING is "<<"["<<head->info<<"]"<<endl;
			
		}
		
		void print(){
			temp = head;
			do{
				if(head == NULL){
					cout<<" List is empty!!! "<<endl;
					return;
				}
				cout<<" ["<<temp->info<<"] ";
				temp=temp->next;
			}
			while(temp != head);
			cout<<endl;
		}
};

int main(){
	
	int input;
	
	JosProb obj;
	
	cout<<" Enter number of nodes : "<<endl;
	cin>>input;
	for(int i=0; i<input; i++){
			obj.createList();
	}
	obj.print();
	
	obj.JProb();
}











