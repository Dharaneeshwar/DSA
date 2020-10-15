#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
};

// Function to create a new binary tree node having given key
Node *newNode(int key)
{
    Node *node = new Node();
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *insert(Node *root, int key)
{
    if (root == nullptr)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}
Node *ancestor(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return ancestor(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return ancestor(root->right, n1, n2);
    return root;
}
int main()
{
    Node *root = nullptr;
    int v;
    while (1)
    {
        cin >> v;
        if (v < 0)
        {
            break;
        }
        root = insert(root, v);
    }
    int c1, c2;
    cin >> c1 >> c2;
    cout << "Enter the value of n1 and n2:" << endl;
    cout << "Common ancestor of " << c1 << " and " << c2 << " is " << ancestor(root, c1, c2)->data;

    return 0;
}