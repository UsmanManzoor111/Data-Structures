#include <iostream>
using namespace std;

struct node
{
	int info;
	node *left;
	node *right;
};
class BST
{
private:
	node *par;
	node *curr;

public:
	int value;
	node *x;
	node *root;
	BST()
	{
		value = 0;
		;
		root = curr = NULL;
	}

	node *createNode(int value)
	{
		node *newnode = new node;
		newnode->info = value;
		newnode->left = NULL;
		newnode->right = NULL;

		return newnode;
	}

	node *min(node *curr)
	{
		if (curr->left == NULL)
		{
			return curr;
		}
		min(curr->left);
		return curr;
	}

	node *max(node *curr)
	{
		if (curr->right == NULL)
		{
			return curr;
		}
		max(curr->right);
	}

	void inorder(node *curr)
	{
		if (curr == NULL)
		{
			return;
		}
		inorder(curr->left);
		cout << "  " << curr->info;
		inorder(curr->right);
	}

	void options()
	{

		cout << "!!!!!   OPTIONS   !!!!! " << endl;
		cout << "1 for Insertion() " << endl;
		cout << "2 for deletion() " << endl;
		cout << "3 for inorder() " << endl;
	}

	bool Search(node *curr, int value)
	{
		bool found = false;
		if (curr == NULL)
		{
			return found;
		}

		if (curr->info == value)
		{
			found = true;
			return found;
		}
		else if (value < curr->info)
		{
			return Search(curr->left, value);
		}
		else
		{
			return Search(curr->right, value);
		}
	}

	void insertion(node *curr, int value)
	{
		if (root == NULL)
		{
			curr = createNode(value);
			root = curr;
			return;
		}
		if (curr->info == value)
		{
			cout << "duplicate found!!!!" << endl;
			return;
		}
		if (value < curr->info)
		{
			if (curr->left != NULL)
			{
				insertion(curr->left, value);
			}
			else
			{
				curr->left = createNode(value);
				return;
			}
		}
		if (value > curr->info)
		{
			if (curr->right != NULL)
			{
				insertion(curr->right, value);
			}
			else
			{
				curr->right = createNode(value);
				return;
			}
		}
	}

	node *deletion(node *curr, int value)
	{
		if (curr == NULL)
		{
			return curr;
		}
		if (value < curr->info)
		{
			curr->left = deletion(curr->left, value);
		}
		if (value > curr->info)
		{
			curr->right = deletion(curr->right, value);
		}
		else
		{
			// value found !!!
			// case 1:
			if (curr->left == NULL && curr->right == NULL)
			{
				delete curr;
				curr = NULL;
			}
			//case 2:
			else if (curr->left == NULL)
			{
				node *temp = curr;
				curr = curr->right;
				delete temp;
			}
			else if (curr->right == NULL)
			{
				node *temp = curr;
				curr = curr->left;
				delete temp;
			}
			//case 3:
			else
			{
				node *temp = min(curr->right);
				curr->info = temp->info;
				curr->right = deletion(curr->right, temp->info);
			}
		}
		return curr;
	}

	int depth(node *node, int val, int height=0)
	{
		if (node == NULL)
		{
			return 0;
		}
		if (node->info == val)
		{
			return height;
		}
		else
		{
			return (depth(node->left, val, height + 1) | depth(node->right, val, height + 1));
		}
	}
};
int main()
{
	int input, key;
	BST obj;

	obj.insertion(obj.root, 20); //	                       20
	obj.insertion(obj.root, 15); //		         15                      25
	obj.insertion(obj.root, 10); //  	  10         16             24                30
	obj.insertion(obj.root, 13); // 	5    13                                 27       35
	obj.insertion(obj.root, 25); //   1        14                                            40
	obj.insertion(obj.root, 30);
	obj.insertion(obj.root, 27);
	obj.insertion(obj.root, 5);
	obj.insertion(obj.root, 35);
	obj.insertion(obj.root, 24);
	obj.insertion(obj.root, 16);
	obj.insertion(obj.root, 1);
	obj.insertion(obj.root, 14);
	obj.insertion(obj.root, 40);
	obj.inorder(obj.root);
	cout << endl;
	// cout<<"Enter key : "<<endl;
	// cin>>key;

	// bool x=obj.Search(obj.root,key);

	// cout<<x<<endl;
	cout << "Height : " << obj.depth(obj.root, 14, 0) << endl;

	//obj.deletion(obj.root, 25);
	//obj.inorder(obj.root);
	obj.depth(obj.root, 14, 0);
}
