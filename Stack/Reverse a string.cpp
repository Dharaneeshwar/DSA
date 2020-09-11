#include <iostream>
using namespace std;

// class declaration
class Node
{
public:
    char data;
    Node *next;
} *head = NULL;

void append(int data)
{
    // adds the element to the top of Stack
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void display()
{
    // displays the elements of the stack
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "";
        temp = temp->next;
    }
}
int main()
{
    string s;
    getline(cin, s);
    for (char a : s)
    {
        append(a);
    }
    display();
    return 0;
}