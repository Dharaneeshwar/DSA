#include <iostream>
using namespace std;

int sum = 0; // global variable to store sum

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

// finding sum by inorder
void find_sum_by_inorder(Node *root)
{
    if (root == nullptr)
        return;

    find_sum_by_inorder(root->left);
    sum += root->data;
    find_sum_by_inorder(root->right);
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

    find_sum_by_inorder(root); // calculating sum
    
    cout << "Sum of all nodes are " << sum;
    
    return 0;
}