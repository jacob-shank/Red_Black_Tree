//Code written for CS 341 at Butler University

#include "TreeNode.h"

class BinarySearchTree
{
	public:
		BinarySearchTree();
		virtual ~BinarySearchTree();
		TreeNode * getRoot();
		virtual void insert(int value);
		void printTree(TreeNode * root);
		void printTree();
		int getHeight(TreeNode * root);
		int getHeight();
	protected:
		TreeNode * root_;
		
		void printTreeHelp(TreeNode * root);
		int getHeightHelp(TreeNode * root);
		
		//helper
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
};