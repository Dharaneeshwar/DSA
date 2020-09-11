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
void remove2nd()
{
    // removes the second last element
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Deletion of second last element is not possible";
    }
    else
    {
        cout << "Before deleting:" << endl;
        display();
        if (temp->next == NULL)
        {
            cout << "Deletion of second last element is not possible";
        }
        else if (temp->next->next == NULL)
        {
            cout << "After deleting:" << endl;
            head = head->next;
            display();
        }
        else
        {
            cout << "After deleting:" << endl;
            while (temp->next->next->next != NULL)
            {
                temp = temp->next;
            }
            Node *deletethis = temp->next;
            temp->next = temp->next->next;
            free(deletethis);
            display();
        }
    }
}

void display()
{
    // displays the elements in the linked list
    Node *temp = head;
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
    remove2nd();
}