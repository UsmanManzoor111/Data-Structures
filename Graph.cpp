#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *down;
    node *next;
};
class graph
{
private:
    int size;
    int value, index;
    node *head, *temp, *temp2;

public:
    graph()
    {
        head = NULL;
    }

    node *createNode(int data)
    {
        node *newNode = new node;
        newNode->info = data;
        newNode->next = NULL;
        return newNode;
    }

    node *gettail()
    {
        node *iter = head;
        while (iter->down != NULL)
        {
            iter = iter->down;
        }
        return iter;
    }

    void add_vertex(int value)
    {
        if (head == NULL)
        {
            head = createNode(value);
            head->down = NULL;
            return;
        }
        node *tail = gettail();
        node *newnode = createNode(value);
        newnode->down = NULL;
        tail->down = newnode;
    }

    void add_edge(int u, int v)
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->info == u)
            {
                node *newnode = createNode(v);

                while (temp != NULL)
                {
                    if (temp->next == NULL)
                    {
                        temp->next = newnode;
                        return;
                    }
                    temp = temp->next;
                }
                break;
            }
            temp = temp->down;
        }
    }

    int out_degree(int val)
    {
        int count = 0;
        temp = head;
        while (temp != NULL)
        {
            temp2 = temp;
            if (temp->info == val)
            {
                while (temp2->next != NULL)
                {
                    temp2 = temp2->next;
                    count++;
                }
                return count;
            }
            temp = temp->down;
        }
    }
    
    int in_degree(int val)
    {
        int counter;
        temp = head;
        while (temp != NULL)
        {
            temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp2->info == val)
                {
                    counter++;
                }
                temp2 = temp2->next;
            }
            temp = temp->down;
        }
        return counter;
    }

    void print()
    {
        temp = head;
        while (temp != NULL)
        {
            temp2 = temp;
            cout << "vertex  " << temp->info << "  ";
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
                cout << " -> " << temp2->info;
            }
            cout << endl;
            temp = temp->down;
        }
    }
};
int main()
{
    int x, y;
    graph obj;
    obj.add_vertex(1);
    obj.add_vertex(2);
    obj.add_vertex(3);
    obj.add_vertex(4);
    obj.add_vertex(5);

    obj.add_edge(1, 2);
    obj.add_edge(1, 3);
    obj.add_edge(2, 4);
    obj.add_edge(3, 4);
    obj.add_edge(5, 4);
    obj.add_edge(3, 5);
    obj.add_edge(5, 1);
    obj.add_edge(5, 2);
    obj.add_edge(4, 4);
    obj.print();

    cout << "Enter vertex to find outdegree " << endl;
    cin >> x;
    cout << "outdegree of " << x << " = " << obj.out_degree(x) << endl;

    cout << "Enter vertex to find indegree " << endl;
    cin >> y;
    cout << "indegree of " << y << " = " << obj.in_degree(y) << endl;

    return 0;
}