#include <iostream>
using namespace std;

int k; // global variable to store count (for simplicity)

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
void find_kth_smallest(Node *root)
{
    if (root == nullptr)
        return;
    static int count = 1;
    find_kth_smallest(root->left);
    if (count < k)
        count += 1;
    else if (count == k)
    {
        cout << root->data;
        count += 1;
    }
    find_kth_smallest(root->right);
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
    cin >> k;
    cout << "Enter the kth value:" << endl
         << "Smallest kth value ";
    find_kth_smallest(root); // calculating sum
    return 0;
}