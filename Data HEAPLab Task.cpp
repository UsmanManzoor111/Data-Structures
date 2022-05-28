#include<iostream>
#include<math.h>

using namespace std;


struct node{

	int value;
	node* left;
	node* right;

};

class CBT {
	int Num_curNodes; //n will use to calculate num of half nodes that can accumudate in a level 
public:
    int *arr,index;
	node *root,*temp,*last,*P_last;
	int level,arrSize;

	CBT(int size){
		arrSize = size;
	    arr=new int[size];
		root=temp=NULL;
		Num_curNodes=level=0;
		index = 1;
	}


	void insert (node *& point, int num,int L,int n){
		if(root==NULL){
			root=new node;
			root->value=num;
			root->left=NULL;
			root->right=NULL;
			level++;

			P_last=root;
			last=root;
			return;
		}

		if(Num_curNodes == pow(2,level)){
			level++;
			Num_curNodes=0;
		}

		if( n-1 == 0 ){
			if(point->left==NULL){
				point->left=new node;
				point->left->value=num;
				point->left->left=NULL;
				point->left->right=NULL;
				
				P_last=point;
				last=point->left;
			}else{
                point->right=new node;
				point->right->value=num;
				point->right->left=NULL;
				point->right->right=NULL;

				P_last=point;
				last=point->right;			
			}

			Num_curNodes++;
			
			if(Num_curNodes == pow(2,level)){
			
				level++;
				Num_curNodes=0;
			}
			return;
		}
	
		if(Num_curNodes < (pow(2,L) - pow(2,n-1))){
			insert(point->left,num,L-1,n-1);
		}else{
			insert(point->right,num,L,n-1);
		
		}
	}

	//---------traverse-------------
	void traverse (node *point){
		if(point==NULL){
			cout<<"Tree is empty"<<endl;
			return;
		}
		
		cout<<point->value<<" ";
		
		if(point->left!=NULL){
			traverse(point->left);
		}
		
		if(point->right!=NULL){
			traverse(point->right);
		}

	}
	
    void arrayHeap(node *p){
       if(p == NULL){
           cout<<"Heap is empty"<<endl;
       }
       int parent, rightChild, leftChild;
	   
	   parent = p->value;
	   rightChild = p->right->value;
	   leftChild = p->left->value;
	   
	   arr[index] = parent;
	   arr[2*index] = leftChild;
	   arr[2*index + 1] = rightChild;
	   index++;
	   if(p->left->left != NULL)
	        arrayHeap(p->left);
	            
	   if(p->right->right != NULL)
	        arrayHeap(p->right);
    }
	
	 void print(int size){
    	 cout<<"Array Heap : ";
    	 for(int i = 1;i <= size;i++){
    	   cout<<arr[i]<<" ";
    	}
    	 cout<<endl;
	}    
};




int main(){
    int size = 5,i  = 0;

	CBT obj(size);

	for(int j=0;j<size;j++){
		cin>>i;
		obj.insert(obj.root,i,obj.level,obj.level);
	}
    
    cout<<"Heap : "<<endl;
	obj.traverse(obj.root);
    cout<<endl;
    
    obj.arrayHeap(obj.root);
    obj.print(size);
    
	return 0;

}

