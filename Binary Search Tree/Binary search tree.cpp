#include <iostream>
using namespace std;

// node declaration
class Node
{
public:
    int data;
    Node *left, *right;
};

// create new node
Node *newNode(int key)
{
    Node *node = new Node();
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

// traversal -> inorder
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// insert a node
Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return newNode(data); // create a node
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root; // returning the root back to main
}

int main()
{
    Node *root = nullptr;

    int a;

    while (1)
    {
        cin >> a;
        if (a < 0)
        {
            // breaks when input is -1
            break;
        }

        root = insert(root, a); // calling insert function which returns back the modified root
    }

    cout << "Tree values are:" << endl;
    inorder(root);

    return 0;
}