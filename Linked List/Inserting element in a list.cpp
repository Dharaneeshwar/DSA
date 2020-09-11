#include <iostream>
using namespace std;

// class declaration
class Node
{
public:
    int data;
    Node *next;
} *head = NULL;

void append(int data)
{
    // adds the element to the end of Linked List
    Node *temp = head;
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display()
{
    // displays the elements in the linked list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{

    int a;
    while (cin >> a)
    {
        if (a < 0)
        {
            break;
        }
        else
        {
            append(a);
        }
    }
    display();
    return 0;
}