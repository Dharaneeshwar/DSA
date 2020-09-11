#include <iostream>
#include <cstring>
using namespace std;

// class declaration
class Node
{
public:
    char data;
    Node *next;
} *head = NULL;

void append(char data)
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

char poptop()
{
    // removes and returns the top of stack
    char val = head->data;
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return val;
}

int main()
{
    string s;
    cin >> s;
    for (char a : s)
    {
        if (a == ')')
        {
            int flag = 0;
            char t = poptop();
            while (t != '(')
            {
                // removes all character till opening paranthesis
                if (strchr("+-*/", t))
                {
                    flag = 1;
                }
                t = poptop();
            }
            if (flag == 0)
            {
                cout << "Yes";
                return 0;
            }
        }
        else
        {
            append(a);
        }
    }
    cout << "No";
    return 0;
}