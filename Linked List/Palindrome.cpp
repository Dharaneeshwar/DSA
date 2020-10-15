#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
} *head = NULL;
bool isPalindrome(Node *head)
{
    Node *fast = head, *slow = head, *rev = NULL, *next_slow;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        next_slow = slow->next;
        slow->next = rev;
        rev = slow;
        slow = next_slow;
    }
    if (fast)
    {
        slow = slow->next;
    }
    while (slow)
    {
        if (slow->data != rev->data)
        {
            return false;
        }
        slow = slow->next;
        rev = rev->next;
    }
    return true;
}
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
void display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    //Type your code here
    char v[1000];
    int c = 0;
    cin >> v;
    string n = "";
    while (v[c] != '\0')
    {
        append(v[c]);
        n += v[c];
        for (int i = n.length() - 1; i >= 0; i--)
        {
            cout << n[i] << endl;
        }
        if (isPalindrome(head))
        {
            cout << "Is Palindrome" << endl
                 << endl;
        }
        else
        {
            cout << "Not Palindrome" << endl
                 << endl;
        }
        c++;
    }
    return 0;
}