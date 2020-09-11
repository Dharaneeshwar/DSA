#include <iostream>
using namespace std;

// class declaration
class Node
{
public:
    int data;
    Node *next;
} *head = NULL;
int out = 0;
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
int present(int k)
{
    // checks if the element is present in the list
    int flag = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
            flag = 1;
        temp = temp->next;
    }
    return flag;
}

int main()
{
    int a,k;
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
    cout << "Enter the value to be searched:" << endl;
    cin >> k;
    if (present(k))
        cout << k << " is present in the list";
    else
        cout << k << " is not present in the list";
    return 0;
}