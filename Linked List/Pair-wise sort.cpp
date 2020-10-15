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
    int flag = 0;
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
            if (temp->data == data)
                flag = 1;
            temp = temp->next;
        }
        if (flag == 0)
            temp->next = newnode;
    }
}
void pairswap()
{
    // swaps the elements in the linked list in pairs
    Node *temp = head;
    while ((temp->next != NULL && temp->next->next != NULL))
    {
        int temp_data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = temp_data;
        temp = temp->next->next;
    }
    if (temp->next != NULL)
    {
        int temp_data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = temp_data;
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
    pairswap();
    display();
}