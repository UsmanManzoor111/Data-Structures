#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class Link_List{
private:
		int value;
		node *head,*temp,*curr;
public:
		Link_List(){
			head=NULL;
		}
		
		node *createNode(int data){
			node *newNode=new node;
			newNode->info=data;
			return newNode;
		}
		
		node *gettail(){
			node *iter=head;
			while(iter->next != NULL){
				iter=iter->next;
			}
			return iter;
		}
		
		
		
		void create_list(){
			
			cout<<"Enter input :"<<endl;
			cin>>value;
			
			if(head==NULL){	
				head=createNode(value);
				head->next=NULL;
				return;
			}
			
			node *tail=gettail();
			node *NewNode=createNode(value);
			NewNode->next=NULL;
			tail->next=NewNode;
		}

		void reverse()
		{
			curr = head;
			node *next = NULL;
			node *prev = NULL;			
			
			while(curr != NULL)
			{
				next=curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
		}
		
		void insertion(){
			int key;
			temp=head;
			cout<<"for insertion after which value you want to insert : "<<endl;
			cin>>key;
			while(temp!=NULL){
				if(temp->info==key){
					cout<<"Enter input"<<endl;
					cin>>value;
					node *insert=createNode(value);
					insert->next=temp->next;
					temp->next=insert;
					return;
				}
				temp=temp->next;
			}
		}
		
		bool searching(int key){
			bool found=false;
			if(head==NULL){
				cout<<"list is empty :"<<endl;
				return found;
			}
	
			temp=head;
			
			while(temp != NULL){
				if(temp->info==key){
					found=true;
					break;
				}
				temp=temp->next;
			}
			if(found==false)
				cout<<"Value not found : "<<endl;	
			else
				return found;
		}
		void deletion(){
			int key=0;
			if(head==NULL){
				cout<<"List is empty : "<<endl;
				return;
			}
			temp=head;
			cout<<"Enter key to delete : "<<endl;
			cin>>key;
			if(temp->info==key){
				head=head->next;
				return;
			}
			while(temp!=NULL){
				if(temp->next->info==key){
					node *curr=temp->next;
					temp->next=temp->next->next;
					delete curr;
					return;
				}
				temp=temp->next;
			}
		}
		void replacing_value(){
			int key;
			if(head==NULL){
				cout<<"List is Empty : "<<endl;
				return;
			}
			temp=head;
			cout<<"Enter key to replace : "<<endl;
			cin>>key;
			while(temp!=NULL){
				if(temp->info==key){
					cout<<"Enter value : "<<endl;
					cin>>value;
					temp->info=value;
					return;
				}
				temp=temp->next;
			}
			
		}
		void print(){
			if (head == NULL){
				cout<<"List is Empty: "<<endl;
				return;		
			}
			
			temp=head;
			
			while(temp != NULL){
				cout<<" ["<<temp->info<<" ]"<<"  "; 
				temp=temp->next;
			}
			cout<<endl;
			
 		}
	
			
			
};
int main(){
	
	int key,x;
	Link_List obj;
	
	cout<<"Enter number of nodes!!!"<<endl;
	cin>>x;
	for(int i=0 ;i<x ;i++){
		obj.create_list();
	}
	obj.print();
	
	obj.reverse();
	
	obj.print();
//	
//	obj.insertion();
//	cout<<"Enter value to search : ";
//	cin>>key;
//	cout<<obj.searching(key);
//	obj.deletion();
//	obj.replacing_value();
//	obj.print();
	
	return 0;
}
