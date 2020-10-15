#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *head1 = NULL, *head2 = NULL, *head;
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
void append1(int val)
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
            temp = temp->next;
        }
        temp->next = newn;
    }
}
void append2(int val)
{
    Node *temp = head2;
    Node *newn = new Node();
    newn->data = val;
    newn->next = NULL;
    if (head2 == NULL)
    {
        head2 = newn;
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
void display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
int main()
{
    int n1, n2, v;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> v;
        append1(v);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> v;
        append2(v);
    }
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            append(head1->data);
            head1 = head1->next;
        }
        else if (head2->data < head1->data)
        {
            append(head2->data);
            head2 = head2->next;
        }
        else
        {
            append(head1->data);
            append(head2->data);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    while (head1)
    {
        append(head1->data);
        head1 = head1->next;
    }
    while (head2)
    {
        append(head2->data);
        head2 = head2->next;
    }
    display();
    return 0;
}