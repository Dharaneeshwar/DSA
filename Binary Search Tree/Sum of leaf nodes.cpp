#include <iostream>
using namespace std;

int sum = 0;  // global variable to store sum

// node declaration
class Node{
public:
  int data;
  Node *left,*right;
};

// create new node
Node* newnode(int data){
  Node *temp = new Node();
  temp->data = data;
  temp->left = temp->right = nullptr;
  return temp;
}

// insert a node
Node* insert(Node* root,int data){
	if (root==nullptr){
    	return newnode(data);
    }
  	if (data<root->data){
    	root->left = insert(root->left,data);	
    }
  	else{
    	root->right = insert(root->right,data);
    }
  return root;
}

// finding sum of leaf nodes by inorder
void find_sum_of_leaf_inorder(Node *root){
  	if (root==nullptr){
    	return;
    }
	find_sum_of_leaf_inorder(root->left);
  	if (root->left==nullptr && root->right==nullptr)
      	sum+=root->data;
  	find_sum_of_leaf_inorder(root->right);
}

int main() 
{
  	Node *root = new Node();
   	int a;
  	while (1){
    	cin>>a; // gets input still -1 is encountered
      	if (a==-1){
        	break;
        }
      	root = insert(root,a); // inserts in the BST
    }

  	find_sum_of_leaf_inorder(root); 

  	cout<<"Sum of all leaf nodes are "<<sum;
    
    return 0;
}