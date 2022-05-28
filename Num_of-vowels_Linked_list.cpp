#include<iostream>
using namespace std;

struct node{
	string info;
	node *next;
};

class list{
	private:
		node *head;
		node *curr;
		node *temp;
		int size;
		string value;
		int count;	
	public:
		list(){
			head=NULL;
			count=0;
		}
		
		node *createNode(string data){
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
			cout<<"Enter inputs :"<<endl;
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
			}
			cout<<endl;
		}
		
		void vowels(){
			node *iter=head;
			string x,vr;
			int count2=0;
			while(iter!= NULL){
				
				x=iter->info;
				
				for(int i=0 ;i<x.length();i++){
					if(x[i] == 'a' || x[i] == 'e'|| x[i] == 'i'|| x[i] == 'o'|| x[i] == 'u'){
						count++;	
					}
				}
				if(count2 < count){
					vr=iter->info;
					count2 = count;
				}
				iter=iter->next;
				count = 0;
			}
			cout<<"max number of vowels in a "<<vr<<" = "<<count2<<endl;
		}
};
int main(){
	
	int num,input;
	
	list obj;
	
	cout<<"To find vowels words // int/char/string : \n\n";
	
	cout<<"Enter number of nodes : \n\n";
	cin>>num;
	
	for(int i=0;i<num;i++){
		obj.create_List();	
	}
	obj.print();
	
	obj.vowels();
	

	
	return 0;	

}
