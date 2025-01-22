//Code written for CS 341 at Butler University

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root_(nullptr)
{
	
}
BinarySearchTree::~BinarySearchTree()
{
	if(root_ != nullptr)
	{
		delete root_;
	}
}
TreeNode * BinarySearchTree::getRoot() 
{
	return root_;
}
void BinarySearchTree::insert(int value)
{
	TreeNode * node = new TreeNode(value);
	
	root_ = insertNode(root_,node);
}
int BinarySearchTree::getHeight()
{
	return getHeightHelp(root_);
}
int BinarySearchTree::getHeight(TreeNode * root)
{
	return getHeightHelp(root);
}
void BinarySearchTree::printTree(TreeNode * root)
{
	printTreeHelp(root);
	std::cout << std::endl;
}
void BinarySearchTree::printTree()
{
	printTreeHelp(root_);
	std::cout << std::endl;
}


//Recursive Helpers
int BinarySearchTree::getHeightHelp(TreeNode * root)
{
	//base case: reached a null node
	if(root == nullptr)
	{
		return 0;
	}
	
	//recursive cases:
	//1. Left subtree is taller
	//2. Right subtree is taller
	
	int rightHeigth(0), leftHeight(0);
	
	rightHeigth = getHeightHelp(root->getRightChild());
	leftHeight = getHeightHelp(root->getLeftChild());
	
	if(rightHeigth > leftHeight)
	{
		//std::cout << "Returned right height" << std::endl;
		return rightHeigth + 1;
	}
	else
	{
		//std::cout << "Returned left height" << std::endl;
		return leftHeight + 1;
	}
}
void BinarySearchTree::printTreeHelp(TreeNode * root)
{
	if(root == nullptr)
	{
		return;
	}
	
	printTreeHelp(root->getLeftChild());
	
	std::cout << root->getData() << " ";
	
	printTreeHelp(root->getRightChild());
}
TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * newNode)
{
	if(root == nullptr)
	{
		return newNode;
	}
	else
	{
		if(newNode->getData() < root->getData())
		{
			//recurse on left subtree
			root->setLeftChild(insertNode(root->getLeftChild(), newNode));
			root->getLeftChild()->setParent(root);
		}
		else //else because we have no duplicate data
		{
			//recurse on right subtree
			root->setRightChild(insertNode(root->getRightChild(), newNode));
			root->getRightChild()->setParent(root);
		}
		
		return root;
	}
}