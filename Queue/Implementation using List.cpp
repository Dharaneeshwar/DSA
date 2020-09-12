#include <iostream>
using namespace std;

// class declaration
class Node
{
public:
    int data;
    Node *next;
} *front = NULL, *rear = NULL;

void append(int a)
{
    // adds the element to the Queue
    Node *newnode = new Node();
    newnode->data = a;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    // displays the elements in the Queue
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    int a;
    while (1)
    {
        cin >> a;
        if (a < 0)
        {
            break;
        }
        append(a);
    }
    display();
    return 0;
}