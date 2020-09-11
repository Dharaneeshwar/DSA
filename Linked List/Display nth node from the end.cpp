#include <iostream>
using namespace std;

int k, flag = 0;

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
void findnthnode()
{
    // finds the nth node from the end
    Node *temp = head;
    while (temp != NULL)
    {
        int num_of_digits_after = 0;
        Node *temp1 = temp;
        while (temp1 != NULL)
        {
            temp1 = temp1->next;
            num_of_digits_after++;
        }

        if (num_of_digits_after == k)
        {
            cout << temp->data << " is the nth node element in the list";
            flag = 1;
        }
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
    cout << "Enter the nth node:" << endl;
    cin >> k;
    findnthnode();
    if (flag == 0)
    {
        cout << "There is no nth node in the list";
    }
    return 0;
}