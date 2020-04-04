#include "BTree.h"

BTreeNode::BTreeNode(double x, BTreeNode* leftp, BTreeNode* rightp)
{
	value = x;
	left = leftp;
	right = rightp;
}


int BST::height() // return the tree height
{
	return height(treeRoot);
}
void BST::insert(double x) //access private insert function
{
	insert(treeRoot, x);
}
void BST::insert(BTreeNode *rootPtr, double x) //insert numbers into the binary tree
{
	if (treeRoot == NULL)  //Base case: assign a new node to treeRoot
	{
		BTreeNode* newNode = new BTreeNode(x, NULL, NULL);
		treeRoot = newNode;
	}
	else if (x <= rootPtr->value) //Traverse to the left of the tree if value x is <= rootPtr value
	{
		if (rootPtr->left != NULL) // As long as left of the tree is not null
		{
			insert(rootPtr->left, x); // We recursive call the function again with left subtree 
		}
		else //Otherwise,
		{
			BTreeNode* newNode = new BTreeNode(x, NULL, NULL); //We create newNode
			rootPtr->left = newNode; // Assign newNode to the left of the tree 
		}
	}
	else if (x > rootPtr->value)//Traverse to the right of the tree if value x is > rootPtr value
	{

		if (rootPtr->right != NULL) // As long as right of the tree is not null
		{
			insert(rootPtr->right, x); //We recursive call the function again with the right subtree
		}
		else //Otherwise,
		{
			BTreeNode* newNode = new BTreeNode(x, NULL, NULL); //We create a newNode
			rootPtr->right = newNode; //Assign newNode to the right of the tree
		}
		
	}
	
}
void BST::inorder()  //access private inorder function
{
	inorder(treeRoot);
}

int BST::leafCounter() //count the number of leaves
{
	return leafCounter(treeRoot);
}
BST::BST()
{
	treeRoot = NULL; //Empty tree
}

void BST::inorder(BTreeNode* t) //print out inorder numbers
{
	if (t == NULL) //Base case for recursion, return on NULL tree
	{
		return;
	}
	else { //Otherwise,
		if (t->left != NULL) //If left subtree is not NULL
		{
			inorder(t->left); //Call function again with tree->left as parameter
		}
		cout << t->value << " "; //Print out the value in tree
		if (t->right != NULL) //If right subtree is not NULL
		{
			inorder( t->right);//Call function again with tree->right as parameter
		}
	}
}
int BST::leafCounter(BTreeNode* t) //count the number of leaves
{
	if (t == NULL)//If we hit a NULL then we return 0
	{
		return 0;
	}
	else if ((t->right == NULL)	 && (t->left == NULL)) //A leaf is a node that has left AND right ptrs NULL so we return 1
	{
		return 1;
	}
	else {
		return leafCounter(t->right) + leafCounter(t->left); //Keep adding leaf count of left and right subtree
	}
}
int BST::height(BTreeNode* t) //calculate the height of the tree
{
	if (t == NULL) //If we hit a NULL then we return 0
	{
		return 0;
	}
	return (height(t->left), height(t->right)) + 1; //We return height so left and right functions get added by +1 
}