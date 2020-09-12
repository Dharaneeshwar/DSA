#include <iostream>
using namespace std;

// class declaration
class Node
{
public:
    int data;
    int priority;
    Node *next;
} *front = NULL;

void append(int data, int priority)
{
    // adds the element to the Queue based on priority
    Node *newnode = new Node();
    newnode->data = data;
    newnode->priority = priority;
    if (front == NULL)
    {
        front = newnode;
    }
    else
    {
        if (front->priority > priority)
        {
            newnode->next = front;
            front = newnode;
        }
        else
        {
            Node *temp = front;
            while (temp->next != NULL && priority > temp->next->priority)
            {
                temp = temp->next;
            }
            if (temp->next != NULL)
            {
                newnode->next = temp->next;
                temp->next = newnode;
            }
            else
            {
                temp->next = newnode;
            }
        }
    }
}

void display()
{
    // displays the elements in the queue
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
    int a, p;
    while (1)
    {
        cout << "Enter the value to insert:" << endl;
        cin >> a;
        if (a == -1)
        {
            // breaks the input loop when -1 is encountered
            break;
        }
        cout << "Enter the priority of that value:" << endl;
        cin >> p;
        append(a, p);
    }
    display();
    return 0;
}