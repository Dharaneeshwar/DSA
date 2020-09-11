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
int poptop()
{
    // removes and returns the top of stack
    int val = head->data;
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return val;
}
int finalvalue()
{
    // returns the value of the expression 
    return head->data;
}
int main()
{
    string s;
    getline(cin, s);
    for (char a : s)
    {
        if (isdigit(a))
        {
            append(a - 48);
        }
        else
        {
            int val1, val2;
            // pop 2 values from the stack
            val1 = poptop();
            val2 = poptop();
            // calculate based on operator
            switch (a)
            {
            case '+':
                append(val1 + val2);
                break;
            case '-':
                append(val1 - val2);
                break;
            case '*':
                append(val1 * val2);
                break;
            case '/':
                append(val1 / val2);
                break;
            }
        }
    }
    cout << "Answer is " << finalvalue();
    return 0;
}