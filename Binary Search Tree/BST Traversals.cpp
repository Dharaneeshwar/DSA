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
Node *newnode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

// insert a node
Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return newnode(data);
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// inorder traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preorder traversal
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// postorder traversal
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    int n, a;
    Node *root = new Node();
    root = nullptr;
    cin >> n; // n integers
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        root = insert(root, a); // calling insert function which returns back the modified root
    }

    // printing the traversal
    cout << "In-Order Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Pre-Order Traversal: ";
    preorder(root);
    cout << endl;
    cout << "Post-Order Traversal: ";
    postorder(root);
    return 0;
}