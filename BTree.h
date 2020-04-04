#include <iostream>
using namespace std;
class BTreeNode
{
public:

	BTreeNode(double x, BTreeNode* leftp, BTreeNode* rightp);
private:
	double value;
	BTreeNode* left, * right;
	friend class BST;
};

class BST
{
public:
	int height(); // return the tree height
	void insert(BTreeNode *rootPtr, double x); //insert numbers into the binary tree
	void insert(double x);
	void inorder();  //accesss private inorder function
	int leafCounter(); //access private leafCounter
	BST();

private:
	void inorder(BTreeNode* t); //order the nodes in the trees
	int leafCounter(BTreeNode* t); //count the number of leaves
	static int height(BTreeNode* t); //calculate the height of the tree
	BTreeNode* treeRoot;
};