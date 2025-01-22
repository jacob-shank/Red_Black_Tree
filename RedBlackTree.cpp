//Code written for CS 341 at Butler University

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : BinarySearchTree()
{
	
}
RedBlackTree::~RedBlackTree()
{
	//nothing to do since we inherit from BinarySearchTree
}
void RedBlackTree::insert(int value)
{
	//does normal insert then balances and colors
	TreeNode * node = new TreeNode(value);
	
	root_ = insertNode(root_,node);

	node->setColor('R'); //done here so that balance color wont change all the nodes to red as it recurses up
	balanceColor(root_,node);
}

//print functions
void RedBlackTree::printColorNodesInOrder(char color, TreeNode * root)
{
	printColorInOrderHelp(color,root);
	std::cout << std::endl;
}
void RedBlackTree::printColorNodesPreOrder(char color, TreeNode * root)
{
	printColorPreOrderHelp(color,root);
	std::cout << std::endl;
}
void RedBlackTree::printRedNodes(TreeNode * root)
{
	std::cout << "Red Nodes: ";
	printColorNodesInOrder('R',root);
}
void RedBlackTree::printBlackNodes(TreeNode * root)
{
	std::cout << "Black Nodes: ";
	printColorNodesPreOrder('B',root);
}

//private functions

//makes the right child of the root the new root
void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
	//return;
	//std::cout << "\t\tROTATE LEFT ON: " << newNode->getData() << std::endl;
	
	if(newNode->getParent() != nullptr)
	{
		bool isLeftSubTree = false;
		TreeNode * subTreeParent = newNode->getParent();
		if(newNode == subTreeParent->getLeftChild())
		{
			isLeftSubTree = true;
			subTreeParent->setLeftChild(nullptr);
		}
		else
		{
			subTreeParent->setRightChild(nullptr);
		}
		
		//now cut the subtree off
		newNode->setParent(nullptr);
		
		//now rotate the subtree and reattach
		rotateSubTreeLeft(newNode); //since new node is *&, it will change to the new root of the sub tree
		
		if(isLeftSubTree)
		{
			subTreeParent->setLeftChild(newNode);
		}
		else
		{
			subTreeParent->setRightChild(newNode);
		}
	}
	else
	{
		//newNode does not point to a subtree, rotate and update the root
		rotateSubTreeLeft(newNode);
		root = newNode;
	}
	//std::cout << newNode->getData() << std::endl;
}
void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
	//return;
	//std::cout << "\t\tROTATE RIGHT ON: " << newNode->getData() << std::endl;
	
	if(newNode->getParent() != nullptr)
	{
		bool isLeftSubTree = false;
		TreeNode * subTreeParent = newNode->getParent();
		if(newNode == subTreeParent->getLeftChild())
		{
			isLeftSubTree = true;
			subTreeParent->setLeftChild(nullptr);
		}
		else
		{
			subTreeParent->setRightChild(nullptr);
		}
		
		//now cut the subtree off
		newNode->setParent(nullptr);
		
		//now rotate the subtree and reattach
		rotateSubTreeRight(newNode); //since new node is *&, it will change to the new root of the sub tree
		
		if(isLeftSubTree)
		{
			subTreeParent->setLeftChild(newNode);
		}
		else
		{
			subTreeParent->setRightChild(newNode);
		}
	}
	else
	{
		//newNode does not point to a subtree, rotate and update the root
		rotateSubTreeRight(newNode);
		root = newNode;
	}
	//std::cout << newNode->getData() << std::endl;
}
void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
	//std::cout << "\nBalancing on  " << newNode->getData() <<std::endl;
	
	/*
	1. reached the root (base case)
			-> set root to black and return
	2. node does not have a grandparent (generation 2) (no rule can be brocken if the node is only in the second gen)
			-> recurse to root
	3. node is black
			-> recurse to parent
	4. parent is black
			-> recurse to parent
	5. Other wise and uncle is black or null (secondary base case)
			-> parent is left child
				-> child is left child
					-> rotate right on the grandparent
				-> child is right child
					-> rotate left on parent
					-> rotate right on grandparent
			-> parent is right child
				-> child is left child
					-> rotate right on parent
					-> rotate left on grandparent
				-> child is right child
					->rotate left on grandparent
	6. Otherwise and Uncle is red
			-> push blackness down from grandparent, recurse to parent
	*/			
	
	//start by making the node red on insertion
	//newNode->setColor('R');
	
	
	//case 1
	if(newNode == root)
	{
		//std::cout << "\tCase 1" << std::endl;
		newNode->setColor('B');
		return;
	}
	
	//can be done since newNode is not the root
	TreeNode * parent = newNode->getParent(); //declared here so it can be used later
	
	//case 2
	if(parent == root)
	{
		//std::cout << "\tCase 2" << std::endl;
		balanceColor(root,parent);
		return; //do this every recursive call, so the funciton doesn't go on after
	}
	
	//case 3
	if(newNode->getColor() == 'B')
	{
		//std::cout << "\tCase 3" << std::endl;
		balanceColor(root,parent);
		return;
	}
	
	//case 4
	if(parent->getColor() == 'B')
	{
		//std::cout << "\tCase 4" << std::endl;
		balanceColor(root,parent);
		return;
	}
	
	//now we know that it is not cases 1,2,3,4
	//                            -> has parent and grandparent, is red and parent is red
	
	//now get a bunch of information about the tree
	
	TreeNode * uncle = newNode->getUncle(); //could be null
	TreeNode * gparent = newNode->getGParent();
	
	//std::cout << "Parent (" << parent->getData() << "): " << parent->getColor() << std::endl;
	//::cout << "Grandparent (" << gparent->getData() << "): " << gparent->getColor() << std::endl;
	/*if(uncle != nullptr)
	{
		std::cout << "Uncle (" << uncle->getData() << "): " << uncle->getColor() << std::endl;
	}
	else
	{
		std::cout << "NULL UNCLE" << std::endl;
	}*/
	
	//case 5
	if((uncle == nullptr) || (uncle->getColor() == 'B'))
	{
		//std::cout << "\tCase 5" << std::endl;
		//then we need to do rotations
		
		//parent is a left child of gparent
		if(parent == gparent->getLeftChild())
		{
			//std::cout << "\t\t\tParent Left child" << std::endl;
			//child is a left child
			if(newNode == parent->getLeftChild())
			{
				//std::cout << "\t\t\t\tChild Left child" << std::endl;
				rotateRight(root,gparent);
			}
			else //newNode is a right child
			{
				//std::cout << "\t\t\t\tChild Right child" << std::endl;
				rotateLeft(root,parent);
				rotateRight(root,gparent); //gparent is no longer the grandparent of newNode, as newNode has moved up the tree, but it is still the node we want
			}
		}
		else //parent is a right child
		{
			//std::cout << "\t\t\tParent Right child" << std::endl;
			//child is a left child
			if(newNode == parent->getLeftChild())
			{
				//std::cout << "\t\t\t\tChild Left child" << std::endl;
				rotateRight(root,parent);
				rotateLeft(root,gparent); //gparent is no longer the grandparent of newNode, as newNode has moved up the tree, but it is still the node we want
			}
			else //new node is right child
			{
				//std::cout << "\t\t\t\tChild Right child" << std::endl;
				rotateLeft(root,gparent);
			}
		}
		
		//don't recurse here, because if all we do is rotate, it retains the number of black nodes in a subtree
		return;
	}
	
	//case 6
	if(uncle->getColor() == 'R')
	{
		//std::cout << "\tCase 6" << std::endl;
		//then push down the grandparents color
		gparent->setColor('R');
		
		//can do the following because the program already caught when the uncle was null
		gparent->getLeftChild()->setColor('B');
		gparent->getRightChild()->setColor('B');
		
		//std::cout << "\t\tGP Color: " << gparent->getColor() << "\tUncle Color: " << uncle->getColor() << "\tParent Color: " << parent->getColor() << std::endl;
		
		//root may be red now, but the recursive base case is the root, and it sets it to black
		balanceColor(root,parent);
		return;
	}
}


void RedBlackTree::rotateSubTreeLeft(TreeNode *& root)
{
	//function cannot be done
	if(root->getRightChild() == nullptr)
	{
		return;
	}
	
	bool thirdST = false;
	
	//otherwise, split the tree into three parts
	TreeNode * newRoot = root->getRightChild();
	TreeNode * newRootLC;
	if(newRoot->getLeftChild() != nullptr)
	{
		thirdST = true;
		newRootLC = newRoot->getLeftChild();
	}
	
	//now we have pointers to the parts we need, so we can seperate them
	root->setRightChild(nullptr);
	newRoot->setParent(nullptr);
	
	newRoot->setLeftChild(nullptr);
	if(thirdST)
	{
		newRootLC->setParent(nullptr);
	}
	
	//now it is seperated, so put it back together
	newRoot->setColor('B');
	newRoot->setLeftChild(root);
	root->setColor('R');
	root->setParent(newRoot);
	
	if(thirdST)
	{
		root->setRightChild(newRootLC);
		newRootLC->setParent(root);
	}
	
	if(newRoot->getRightChild() != nullptr)
	{
		newRoot->getRightChild()->setColor('R');
	}
	
	//now redirect root to the new root, so that it can be used outside this function
	root = newRoot;
}
void RedBlackTree::rotateSubTreeRight(TreeNode *& root)
{
	//function cannot be done
	if(root->getLeftChild() == nullptr)
	{
		//std::cout << "\t\t\t\t\tcannot do it" << std::endl;
		return;
	}
	
	bool thirdST = false;
	
	//otherwise, split the tree into three parts
	TreeNode * newRoot = root->getLeftChild();
	TreeNode * newRootRC;
	if(newRoot->getRightChild() != nullptr)
	{
		thirdST = true;
		newRootRC = newRoot->getRightChild();
	}
	
	//now disconnect the tree
	root->setLeftChild(nullptr);
	newRoot->setParent(nullptr);
	
	newRoot->setRightChild(nullptr);
	if(thirdST)
	{
		newRootRC->setParent(nullptr);
	}
	
	//now put them back together
	newRoot->setColor('B');
	newRoot->setRightChild(root);
	root->setColor('R');
	root->setParent(newRoot);
	
	if(thirdST)
	{
		root->setLeftChild(newRootRC);
		newRootRC->setParent(root);
	}
	
	if(newRoot->getLeftChild() != nullptr)
	{
		//std::cout << "\t\t\t\tnew root rc: " << newRoot->getRightChild()->getColor() << std::endl;
		newRoot->getLeftChild()->setColor('R');
	}
	
	//now redirect the pointer
	root = newRoot;
}


//helpers
void RedBlackTree::printColorInOrderHelp(char color, TreeNode * root)
{
	//do an inorder traversal, but only print if the color is desired
	
	//base case: gone too far
	if(root == nullptr)
	{
		return;
	}
	
	//otherwise, recurse
	//In order: LNR
	
	//Left
	printColorInOrderHelp(color,root->getLeftChild());
	
	//Node
	if (root->getColor() == color)
	{
		std::cout << root->getData() << " ";
	}
	
	//Right
	printColorInOrderHelp(color,root->getRightChild());
}
void RedBlackTree::printColorPreOrderHelp(char color, TreeNode * root)
{
	//do an inorder traversal, but only print if the color is desired
	
	//base case: gone too far
	if(root == nullptr)
	{
		return;
	}
	
	//otherwise, recurse
	//Pre order: NLR
	
	//Node
	if (root->getColor() == color)
	{
		std::cout << root->getData() << " ";
	}
	
	//Left
	printColorPreOrderHelp(color,root->getLeftChild());
	
	//Right
	printColorPreOrderHelp(color,root->getRightChild());
}


//test functions
void RedBlackTree::testRotateRight()
{
	rotateRight(root_,root_);
	printTree();
	std::cout << "Root: " << root_->getData() << std::endl;
}
void RedBlackTree::testRotateLeft()
{
	rotateLeft(root_,root_);
	printTree();
	std::cout << "Root: " << root_->getData() << std::endl;
}