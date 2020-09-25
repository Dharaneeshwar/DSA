#include <bits/stdc++.h> 
using namespace std; 

class Node 
{ 
	public: 
	int data; 
	Node* left, *right; 
}; 

// calulate height
int height(Node* node) 
{ 
	if (node == NULL) 
		return 0; 
	else
	{ 
		// compute the height of each subtree   
		int lheight = height(node->left); 
		int rheight = height(node->right); 

		// use the larger one 
		if (lheight > rheight) 
			return(lheight + 1); 
		else 
            return(rheight + 1); 
	} 
} 

/* Print nodes at a given level */
void printGivenLevel(Node* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
		cout << root->data << " "; 
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
} 

// print level order
void printLevelOrder(Node* root) 
{ 
	int h = height(root);  
	for (int i = 1; i <= h; i++) 
		printGivenLevel(root, i); 
} 

// create new node 
Node* newNode(int data) 
{ 
	Node* node = new Node(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
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
	cout << "Level order Traversal: \n"; 
	printLevelOrder(root); 

	return 0; 
} 
