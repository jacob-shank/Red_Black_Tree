//Code written for CS 341 at Butler University

#include <iostream>
#include <fstream>

class TreeNode
{
	public:
		TreeNode();
		TreeNode(int data);
		~TreeNode();
		void setParent(TreeNode *);
		void setLeftChild(TreeNode *);
		void setRightChild(TreeNode *);
		void setData(int data);
		void setColor(char c);
		TreeNode * getParent();
		TreeNode * getLeftChild();
		TreeNode * getRightChild();
		TreeNode * getUncle();
		TreeNode * getGParent();
		int getData();
		char getColor();
		std::string getColorString();
	private:
		TreeNode * leftChild_;
		TreeNode * rightChild_;
		TreeNode * parent_;
		int data_;
		char color_; //"B" = black, "R" = red
};