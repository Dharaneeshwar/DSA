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
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
        return (lheight + 1);
    return rheight + 1;
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
    cout << "Height of the tree is " << height(root);

    return 0;
}