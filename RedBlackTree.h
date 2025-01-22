//Code written for CS 341 at Butler University

#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
	public:
		RedBlackTree();
		//RedBlackTree(RedBlackTree & tree);
		virtual ~RedBlackTree();
		void insert(int value);
		void printColorNodesInOrder(char color, TreeNode * root); // the first param can either be 'R' or 'B'
		void printColorNodesPreOrder(char color, TreeNode * root);
		void printRedNodes(TreeNode * root);
		void printBlackNodes(TreeNode * root);
		
		//test functions
		void testRotateRight();
		void testRotateLeft();
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode); //seperates the subtree from the main tree and gives it to the helper
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode); //when run, an illegal redblack tree becomes legal
		
		void rotateSubTreeRight(TreeNode *& root);
		void rotateSubTreeLeft(TreeNode *& root);
		
		//helpers
		void printColorInOrderHelp(char color, TreeNode * root);
		void printColorPreOrderHelp(char color, TreeNode * root);
};
