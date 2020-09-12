#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
} *front = NULL, *rear = NULL;

void append(int data)
{
    Node *newnode = new Node(data);
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = rear->next;
    }
}
void reverse()
{
    Node *previous = NULL, *temp = front;
    while (temp != NULL)
    {
        Node *next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    rear = front;
    front = previous;
}
void display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
    if (front == NULL)
    {
        cout << "Queue is empty";
        return 0;
    }
    cout << "Before reversing:" << endl;
    display();
    reverse();
    cout << "After reversing:" << endl;
    display();
    return 0;
}