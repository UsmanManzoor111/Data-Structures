#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class list{
	private:
		node *head;
		node *curr;
		node *temp;
		int size,count,value;	
	public:
		list(){
			head=NULL;
		}
		
		node *createNode(int data){
			node *newnode=new node;
			newnode->info=data;
			return newnode;
		}
		
		node *getTail(){
			node *iter=head;
			while(iter->next != NULL){
				iter=iter->next;
			}
			return iter;
		}

		void create_List(){
			cout<<"Enter value : "<<endl;
			cin>>value;
			if(head == NULL){
				head = createNode(value);
				head->next=NULL;
				return;
			}
			
			node *newNode=createNode(value);
			node *tail =getTail();
			newNode->next=NULL;
			tail->next=newNode;
		}
		
		void print(){
			if(head == NULL){
				cout<<"List is empty !!!"<<endl;
				return;
			}
			curr = head;
			while(curr != NULL){
				cout<<"["<<curr->info<<"]  ";
				curr=curr->next;
				count++;
			}
			cout<<endl;
		}
		
		void num_of_nodes(){
			cout<<"total number of nodes : "<<count<<endl;
		}
		
		void max_min_value(){
			int max = head->info;
			temp = head->next;
			while(temp != NULL){
				if(max < temp->info){
					max = temp->info;
				}
				temp=temp->next;
			}
			cout<<"Maximum value : "<<max<<endl;
			
			int min = head->info;
            temp = head->next;
			while(temp != NULL){
				if(min > temp->info){
					min = temp->info;
				}
				temp=temp->next;
			}
			cout<<"Minimum value : "<<min<<endl;	
		}
};
int main(){
	
	int num,input;
	
	list obj;
	
	cout<<"Enter number of nodes : "<<endl;
	cin>>num;
	for(int i=0;i<num;i++){
		obj.create_List();	
	}
	obj.print();
	
	cout<<" press 1 for counting Number of nodes!!! \n press 2 for MAX and MIN value!!! "<<endl;
	cin>>input;
	if(input == 1){
		obj.num_of_nodes();
	}
	if(input == 2){
		obj.max_min_value();	
	}
	else{
		cout<<"Wrong Input!!!"<<endl;
	}
	
	return 0;	

}
