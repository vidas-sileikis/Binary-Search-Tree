#include <iostream>
#include "BTree.h"

using namespace std;

int main()
{
	BST BinTree;
	cout << "This program allows you to insert some numbers in binary search tree.\nIt prints out the numbers in the tree inorder.\nIt computes and prints the number of leaves in the tree.\nand the height of the tree.\n";
	cout << "Enter 10 numbers:";
	for (int i = 0; i < 10; i++)
	{
		double number;
		cin >> number;
		BinTree.insert
		(number);
	}
	cout << "The items in the tree inorder are: ";
	BinTree.inorder();
	cout << "\nThe height of the tree is ";
	cout << BinTree.height();
	cout << "\nThe number of leaves is ";
	cout << BinTree.leafCounter();
	return 0;
}
