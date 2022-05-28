#include<iostream>
using namespace std;

class node{
public: 
    int info;
    node *left;
    node *right;

    node(int val){
        info=val;
        left=NULL;
        right=NULL;
        
    }
};

void preorder(node *ptr){
    if(ptr == NULL){
        return;
    }
    cout<<ptr->info<<"\t";
    preorder(ptr->left);
    preorder(ptr->right);
}

void inorder(node *ptr){
    if(ptr == NULL){
        return;
    }
    inorder(ptr->left);
    cout<<ptr->info<<"\t";
    inorder(ptr->right);
}

void postorder(node *ptr){
    if(ptr == NULL){
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    cout<<ptr->info<<"\t";
}

node *parent(node *curr,int value,node *par){
	if(curr == NULL){
		return NULL;
	}
	if(curr->info == value){
		return par;
	}
	else{
		node *t=NULL;
		t=parent(curr->left,value,curr);
		if(t != NULL){
			return t;
		}
		else{
			t=parent(curr->right,value,curr);
			return t;
		}
	}
}

node *sib(node *curr,int val){
	node *x= parent(curr,val,NULL);
	
	if(x->left->info == val){
		return x->right;
	}
	return x->left;
}

int level(node *curr,int val,int count){
	if(curr == NULL){
		return 0;
	}
	if(curr->info == val){
		return count;
	}
	else{
		return (level(curr->left,val,count+1) | level(curr->right,val,count+1));	
	}
}

int depth(node *node){
	if(node == NULL){
		return -1;
	}
	
	int ldepth=depth(node->left);
	int rdepth=depth(node->right);
	
	if(ldepth > rdepth){
		return (ldepth+1);
	}
	else{
		return (rdepth+1);
	}
}


int balanceofNode(node *curr,int value){
	if(curr == NULL){
		return -1;
	}
	if(curr->info == value){
		int ldepth=depth(curr->left);
		int rdepth=depth(curr->right);
		int balance;
		balance = ldepth-rdepth;
		return balance;
	}
	if(value < curr->info){
		balanceofNode(curr->left,value);
	}
	else{
		balanceofNode(curr->right,value);
	}
}
int maxdepthNode(node *curr,int value){
	if(curr == NULL){
		return -1;
	}
	
	int ldepth=maxdepthNode(curr->left,value);
	int rdepth=maxdepthNode(curr->right,value);
	
	if(curr->info == value){
   		if(ldepth > rdepth){
			return ldepth;
		}
		else{
			return rdepth;
		}
	}	
	if(ldepth > rdepth){
		return (ldepth+1);
	}
	else{
		return (rdepth+1);
	}
}
	//                                9 
    //                       4               15
    //                   1     6          11        20

//void parent(node *curr,int value,node *par){
//    if(curr == NULL){
//        return;
//    }
//    if(curr->info == value){
//        cout<<"Parent : "<< par->info;
//    }
//    else{
//        parent(curr->left,value,curr);
//        parent(curr->right,value,curr);
//    }
//}

int main(){
	int key;
	
    node *root=NULL;
	root=new node(9);       //                                       9 
    root->left=new node(4);         //                       4              15
    root->left->left=new node(1);     //                   1   6         11        20
    root->left->right=new node(6);      //                       7          14     
    root->left->right->right=new node(7); //                       8         
    root->left->right->right->right=new node(8);//
	root->right=new node(15);
    root->right->right=new node(20);
    root->right->left=new node(11);
    root->right->left->right=new node(14);
    
	cout<<"preorder = ";
    preorder(root);
    cout<<endl;

//    cout<<"inoder = ";
//    inorder(root);
//    cout<<endl;
//
//    cout<<"postorder = " ;
//    postorder(root);
//    cout<<endl;
    
//    node *p = parent(root,7,NULL);
//    cout<<"parent : "<<p->info<<endl;
//    
//    node *s=sib(root,11);
//	cout<<"Sibling : "<<s->info<<endl;
//	
//	cout<<"level : "<<level(root,6,0)<<endl;
//	
//	cout<<"depth of a tree : "<<depth(root)<<endl;
	
	cout<<"Enter number to find its balance : "<<endl;
	cin>>key;
	
	cout<<"balance of "<<key <<" = "<<balanceofNode(root,key)<<endl;
	

	cout<<"depth = "<<maxdepthNode(root,key)<<endl;
}

