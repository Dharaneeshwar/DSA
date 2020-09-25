#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
} *root = NULL;

void append(int val)
{
    int flag = 0;
    Node *temp = root;
    Node *temp1 = root;
    Node *newnode = new Node();
    newnode->left = NULL;
    newnode->data = val;
    newnode->right = NULL;
    if (root == NULL)
        root = newnode;
    else
    {
        while (1)
        {
            if (temp->left == NULL)
            {
                temp->left = newnode;
                break;
            }
            else if (temp->right == NULL)
            {
                temp->right = newnode;
                break;
            }
            else if (flag == 0)
            {
                temp = temp1->left;
                flag = 1;
            }
            else
            {
                temp = temp1->right;
                flag = 0;
                temp1 = temp1->left;
            }
        }
    }
}
int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
int main()
{
    int value;
    while (1)
    {
        cin >> value;
        if (value > 0)
            append(value);
        else
            break;
    }
    int a = height(root->left);
    int b = height(root->right);
    cout << "Diameter of the given binary tree is " << a + b + 1;
    return 0;
}