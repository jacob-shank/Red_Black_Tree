//Code written for CS 341 at Butler University

#include "TreeNode.h"

TreeNode::TreeNode() : data_(0), rightChild_(nullptr), leftChild_(nullptr), parent_(nullptr), color_(' ')
{
	
}
TreeNode::TreeNode(int data) : data_(data), rightChild_(nullptr), leftChild_(nullptr), parent_(nullptr), color_(' ')
{
	
}
TreeNode::~TreeNode()
{
	if(leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	if(rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}
void TreeNode::setParent(TreeNode * newParent)
{
	parent_ = newParent;
}
void TreeNode::setLeftChild(TreeNode * newLeftChild)
{
	leftChild_ = newLeftChild;
}
void TreeNode::setRightChild(TreeNode * newRigthChild)
{
	rightChild_ = newRigthChild;
}
void TreeNode::setData(int data)
{
	data_ = data;
}
void TreeNode::setColor(char c)
{
	if((c == 'B') || (c == 'R'))
	{
		color_ = c;
	}
}
TreeNode * TreeNode::getParent()
{
	return parent_;
}
TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}
TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}
TreeNode * TreeNode::getUncle()
{
	//two cases
	//1. parent is left child
	//2. parent is right child
	
	TreeNode * gparent = parent_->getParent();
	
	//if the grandparents left child is the parent, then case 1
	if(gparent->getLeftChild() == parent_)
	{
		return gparent->getRightChild();
	}
	else //parent is the right child
	{
		return gparent->getLeftChild();
	}
}
TreeNode * TreeNode::getGParent()
{
	return parent_->getParent();
}
int TreeNode::getData()
{
	return data_;
}
char TreeNode::getColor()
{
	return color_;
}
std::string TreeNode::getColorString()
{
	if(color_ == 'R')
	{
		return "RED";
	}
	else if (color_ == 'B')
	{
		return "BLACK";
	}
	return "NO COLOR";
}