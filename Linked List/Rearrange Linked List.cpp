#include <iostream>
using namespace std;

// class declaration
class Node
{
public:
    int data;
    Node *next;
} *head = NULL, *head2 = NULL, *output = NULL;

void append(int data)
{
    // adds the element to the end of Linked List
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void append_output(int data)
{
    // forms the linked list to be printed
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;
    if (output == NULL)
    {
        output = newnode;
    }
    else
    {
        Node *temp = output;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void reverse_secondhalf()
{
    // reverses the second list
    Node *previous = NULL;
    Node *temp = head2;
    while (temp != NULL)
    {
        Node *next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    head2 = previous;
}
void display()
{
    // displays the elements in the output list
    Node *temp = output;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    int a, count = 0;
    while (cin >> a)
    {
        if (a < 0)
        {
            break;
        }
        else
        {
            count++;
            append(a);
        }
    }
    int mid = (count + 1) / 2;
    Node *temp = head;
    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    // splits linked list in middle
    head2 = temp; 
    reverse_secondhalf();
    for (int i = 0; i < count; i++)
    {
        // appends to the output list alternatively
        if (i % 2 == 0)
        {
            append_output(head->data);
            head = head->next;
        }
        else
        {
            append_output(head2->data);
            head2 = head2->next;
        }
    }
    display();
    return 0;
}