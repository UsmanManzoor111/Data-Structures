#include<iostream>
using namespace std;
struct node
{
   int data;
   node *left;
   node *right;
};
class AVL{
    int balance;
    public:
    node *root,*temp;
    
   AVL()
   {
       root=NULL;
       temp=NULL;
   }
   node *leftleftcase(node *temp)
   {
       node *temp1,*temp2;
       temp1=temp->right;
       temp2=temp1->left;
       temp1->left=temp;
       temp->right=temp2;
       return temp1;
      
   }
   node *right_rightcase(node *temp)
   {
       node *temp1,*temp2;
        temp1=temp->left;
        temp2=temp1->right;
        temp1->right=temp;
        temp->left=temp2;
       return temp1;
   }
  int  height_node(node *temp2)
  {
     if(temp2==NULL)
     {
         return 0;
     }
     int ldepth=height_node(temp2->left);
     int rdepth=height_node(temp2->right);
     if(ldepth>rdepth)
     {
         return ldepth+1;
     }
     else return rdepth+1;
    }
  int balance_factor(node *tmep)
  {
      if(tmep==NULL)
          return 0;
      int balance;
      int lefttree=height_node(tmep->left);
      int righttree=height_node(tmep->right);
      balance=lefttree-righttree;
      return balance;
  }
  node *create_node(int key)
  {
            node* temp;
            temp=new node;
            temp->data=key;
            temp->right=NULL;
            temp->left=NULL;
            return temp;
  }
  	node* findMin(node* temp)
{

    while(temp->left!=NULL)
    {
        temp = temp->left;
    }
    return temp;
}
  node * insertion(node *temp,int key)
  {
      if(temp==NULL)
      {
          return create_node(key);
      }
      if(key>temp->data)
      {
        temp->right=insertion(temp->right,key);     
     }
      if (key<temp->data)
      {
                temp->left=insertion(temp->left,key);
      }
 
           balance=balance_factor(temp);
            if(balance>1&&key<temp->left->data)
              return right_rightcase(temp);
            if(balance<-1&&key>temp->right->data)
                 return leftleftcase(temp);
           if(balance>1&&key>temp->left->data)
            {
                temp->left=leftleftcase(temp->left);
               return right_rightcase(temp);
                
            }
             
           if(balance<-1&&key<temp->right->data)
            {
               temp->right=right_rightcase(temp->right);
               return leftleftcase(temp);
              }
    
             return temp;
   }
   void insert_value(int key)
   {
       root=insertion(root,key);
   }
   void print(node *temp)
   {
       if(temp==NULL)
          return;
        cout<<temp->data<<endl;
        print(temp->left);
        print(temp->right);
 }
 node *deletion(int key,node *temp)
 {
      if(temp==NULL)
       {
           cout<<"NOTHING TO DELETE"<<endl;
                  return NULL;
       }
        if(key<temp->data)
           temp->left=deletion(key,temp->left);
      else if(key>temp->data)
            temp->right=deletion(key,temp->right);
        
        else
        {
            if(temp->left==NULL&&temp->right==NULL)
               {
                   
                    delete temp;
                    temp=NULL;
                    return temp;
               }
             else  if (temp->right==NULL)
               {
            
                   node *temp1=temp;
                   temp=temp->left;
                   delete temp1;
                   return temp;
                }
               else if(temp->left==NULL)
                  {
                  node *temp1=temp;
                      temp=temp->right;
                      delete temp1;
                      return temp;
                  }
               else
               {
                   node *temp2=findMin(temp->right);
                   temp->data=temp2->data;
                   temp->right=deletion(temp2->data,temp->right);
                   
               }
               
        }
           balance=balance_factor(temp);
            if(balance>1&&balance_factor(temp->left)>=0)
              return right_rightcase(temp);
            if(balance<-1&&balance_factor(temp->right)<=0)
                 return leftleftcase(temp);
           if(balance>1&&balance_factor(temp->left)<0)
            {
                temp->left=leftleftcase(temp->left);
               return right_rightcase(temp);
         }
             if(balance<-1&&balance_factor(temp->right)>0)
            {
               temp->right=right_rightcase(temp->right);
               return leftleftcase(temp);
              }
return temp;        
}
void deltion_AVL (int key)
{
   root= deletion(key,root);
}

};

int main()
{
    AVL l;
   l.insert_value(10);
   l.insert_value(20);
   l.insert_value(30);
   l.insert_value(40);
   l.insert_value(25);
   l.insert_value(60);
   l.insert_value(46);
   l.insert_value(39);
   l.insert_value(77);
   l.insert_value(86);
   l.deltion_AVL(40);

	l.print(l.root);
}
