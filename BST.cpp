#include<iostream>
using namespace std;

struct node {
    int value, dupCount;
    node* left, * right;
};

class BST {
private:
    node* temp;
    int key;

public:
    node* root;
    int value, sum;
    BST();
    node* createNode(int);
    void options();
    void insertion(node*);
    void deletion(node*, node*, int);
    void inOrder(node*);
    int duplicateCounter(int, node*);
    int sumOfTree(node*);
    bool Search(node*,int);
};

BST::BST() {
    root = temp = NULL;
    value = key = sum = 0;
}

node* BST::createNode(int value) {
    node* newNode = new node;
    newNode->value = value;
    newNode->dupCount = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void BST::options() {
    cout << "//////////OPTIONS///////" << endl;
    cout << "1-insertion()" << endl;
    cout << "2-deletion()" << endl;
    cout << "3-inOrder()" << endl;
    cout << "4-DupicateCounter()" << endl;
    cout << "Any other number for Exit" << endl;
    cout << endl;
}

void BST::insertion(node* curr,int value) {
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

void BST::inOrder(node* temp) {
    if (root == NULL) {
        cout << endl;
        cout << "tree is empty!!!" << endl;
        return;
    }

    if (temp->left != NULL)
        inOrder(temp->left);
    cout << temp->value << " ";
    if (temp->right != NULL)
        inOrder(temp->right);

    return;
}

void BST::deletion(node leafNode, node parent, int key) {
    //if tree is empty
    if (leafNode == NULL) {
        cout << "tree is empty!!!" << endl;
        return; // important to return
    }

    node* currentParent = leafNode;

    if (key < leafNode->value) {
        return deletion(leafNode->left, currentParent, key); // important to return
    }

    if (key > leafNode->value) {
        return deletion(leafNode->right, currentParent, key); // important to return
    }

    // if program flow reaches here, it means we found the leafNode we want to delete
    //case 1:node deletion, incase, left & right leaf nodes are NULL
    if (leafNode->right == NULL && leafNode->left == NULL) {
        if (parent != NULL) {
            if (parent->left == leafNode) parent->left = NULL;
            else parent->right = NULL;
        }

        delete leafNode;
        leafNode = NULL;
        return; //important to return the flow
    }

    //case 2:node having one child either left or right
    if (leafNode->left != NULL && leafNode->right == NULL) {
        parent->left = leafNode->left;
        leafNode->left = NULL;
        delete leafNode;
        return; //important to return the flow
    }

    if (leafNode->right != NULL && leafNode->left == NULL) {
        parent->right = leafNode->right;
        leafNode->right = NULL;
        delete leafNode;
        return; //important to return the flow
    }

    //case 3:node having 2 childs (simply move to right node, then traverse to the left most node from there and move it to leaf node location)
    node* deleteNode = leafNode;
    deleteNode = leafNode->right;

    while (deleteNode->left != NULL) {
        currentParent = deleteNode;
        deleteNode = deleteNode->left;
    }
    // replace the value of deleteNode with leafNode & then delete deleteNode
    leafNode->value = deleteNode->value;

    delete deleteNode;
    deleteNode = NULL;
    currentParent->left = NULL;
}

int BST::sumOfTree(node* temp) {
    if (root == NULL) {
        cout << "Tree Empty!!!" << endl;
        return 0;
    }
    else {
        if (temp->left != NULL) {
            sum += sumOfTree(temp->left);
        }else if (temp->right != NULL) {
           sum += sumOfTree(temp->right);
        }
        else {
            sum += temp->value;
            return sum;
        }
    }
    return sum;
}
int BST::duplicateCounter(int num, node* temp) {
    if (root == NULL) {
        return 0;
    }

    if (num == temp->value) {
        if (temp->dupCount > 1) {
            temp->dupCount = temp->dupCount - 1;
        }
        return temp->dupCount;
    }
    else if (num > temp->value) {
        duplicateCounter(num, temp->right);
    }
    else if (num < temp->value) {
        duplicateCounter(num, temp->left);
    }
}

bool BST::Search(node *curr,int value){
		bool found = false;
		if(curr == NULL){
			return found;
		}

		if(curr->info == value){
			found = true;
			return found;
		}else if(value < curr->info)
			return Search(curr->left,value);
		}else{
			return Search(curr->right,value);
		}
		return found;
}

int main() {
    BST obj;
    int choice, key, num;

    obj.insertion(obj.root, 20); //	                       20
	obj.insertion(obj.root, 15); //		         15                      25
	obj.insertion(obj.root, 10); //  	  10         16             24                30
	obj.insertion(obj.root, 13); // 		5    13                                 27       35
	obj.insertion(obj.root, 25); //     1           14                                            40
	obj.insertion(obj.root, 30);

    obj.inorder(obj.root);
    // do {
    //     obj.options();
    //     cout << "Enter your choice : ";
    //     cin >> choice;

    //     if (choice == 1) {
    //         cout << "Enter number to insert: ";
    //         cin >> obj.value;
    //         obj.insertion(obj.root);
    //     }
    //     else if (choice == 2) {
    //         cout << "Enter key: ";
    //         cin >> key;
    //         obj.deletion(obj.root, NULL, key);
    //     }
    //     else if (choice == 3) {
    //         obj.inOrder(obj.root);
    //     }
    //     else if (choice == 4) {
    //         cout << "Enter a number to count it's duplicate in tree : ";
    //         cin >> num;
    //         cout << "Answer : " << obj.duplicateCounter(num, obj.root) << endl;
    //     }
    //     else {
    //         exit(0);
    //     }
    // } while (4);

    return 0;
}
