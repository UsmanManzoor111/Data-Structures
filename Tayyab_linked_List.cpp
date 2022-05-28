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
		
		node* searching(int key){
			if(head == NULL){
				cout<<"list is empty :"<<endl;
				return NULL;
			}
	
			temp = head;
			if(head->info == key){
                return head;
            }

			while(temp != NULL){
				if(temp->next->info == key){
					break;
				}
				temp = temp->next;
			}
			return temp;
		}

		void deletion(){
			int key;
			if(head == NULL){
				cout<<"List is empty : "<<endl;
			}
			temp = head;
			cout<<"Enter key to delete : "<<endl;
			cin>>key;

            node *search = searching(key);
            node *del = NULL;
            if(search == head){
                del = head;
                head = head->next;
                delete del;
            }else{
                del = search->next;
                search->next = search->next->next;
                delete del;
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
	
	int key;
	Link_List obj;
	
	obj.create_list();
	obj.create_list();
	obj.create_list();
	obj.create_list();
	obj.print();
	//obj.insertion();
	
	obj.deletion();
	//obj.replacing_value();
	obj.print();
	
	return 0;
}
