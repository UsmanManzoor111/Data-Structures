/* 
What is josephous problem?
You should know about it, we only discuss the code part of it.
*/

//Code don't lie, but comment's sometimes do.
//Code start's from here.

#include<bits/stdc++.h> // Headerfile which include's all headerfile's of c++ language

using namespace std;

struct Node{
    int val;
    Node *next;
};

class Ring{
public:
    Node *current,*head;
    Ring(); // Constructor
    Node* node();
    void list();
    void print();
    void josephous();
};

Ring::Ring(){
    current = head = NULL;
}

Node* Ring::node(){
    Node *newNode = new Node;
    cout<<"Enter value of newNode : ";
    cin>>newNode->val;
    newNode->next = NULL;
    return newNode;
}

void Ring::list(){
    Node *newNode = node();
    if(head == NULL){
        head = newNode;
        head->next = head;
        current = head;
        return;
    }
    
    current->next = newNode;
    current = current->next;
    current->next = head;
}

void Ring::print(){
    if(head == NULL){
        cout<<"List is empty!!!"<<endl;
        return;
    }

    current = head;
    cout<<" [ ";

    do{
        cout << current->val;
        if(current->next != head){
            cout<<" , ";
        }
        current = current->next;
    }while (current != head);
    
    cout<<" ] "<<endl;
}

void Ring::josephous(){
    current = head;
    Node *del = head->next;
	
    //(head->next != head) This condition meets, when there is only one node left in a list
    while(head->next != head){ 
        for(int i = 1;i < 3;i++){
            //we want to delete every 3rd node of ring list
            current = current->next;
            del = del->next;
        }

        /*
            current->next = del->next; because we are going to delete the del node.so,
            As, current pointer is behind the del pointer
            linked previous node with del next node.
            I hope you get it . . .
            If not
            1           2       3
            current     del
            As 2 is going to be deleted.
            so, link 1 with 3
        */

        current->next = del->next; 
        if(del == head){
             //Special Case
            //if del node is head then we have to update the head
            head = head->next;
        }
        cout<<del->val<<" Killed!"<<endl;//This line is just want to know which value is deleted
        delete del;
        current = current->next;
        del = current->next;
    }

    cout<<endl<<"Leader : "<< head->val<<endl;//Leader is here
}

int main(){
    Ring obj;
    obj.list();
    obj.list();
    obj.list();
    obj.list();
    obj.list();

    obj.print();

    obj.josephous();
    return 0;
}
