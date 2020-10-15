#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *head = NULL, *head1 = NULL;
void append(int val)
{
    Node *temp = head;
    Node *newn = new Node();
    newn->data = val;
    newn->next = NULL;
    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}
void append_dup(int val)
{
    Node *temp = head1;
    Node *newn = new Node();
    newn->data = val;
    newn->next = NULL;
    if (head1 == NULL)
    {
        head1 = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == val)
            {
                return;
            }
            temp = temp->next;
        }
        if (temp->data != val)
        {
            temp->next = newn;
        }
    }
}
void display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void display1()
{
    Node *temp = head1;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    //Type your code here
    int v;
    while (1)
    {
        cin >> v;
        if (v > 0)
        {
            append(v);
            append_dup(v);
        }
        else
        {
            break;
        }
    }
    cout << "Linked list before removal of duplicates" << endl;
    display();
    cout << "Linked list after removal of duplicates" << endl;
    display1();
    return 0;
}