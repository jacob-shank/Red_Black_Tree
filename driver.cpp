//Code written for CS 341 at Butler University

#include "RedBlackTree.h"

void inClass();
void phase2();
void phase3();
void phase4();
void fillTree(BinarySearchTree * tree, std::string filename);

int main()
{
	//inClass();
	//phase2();
	//phase3();
	phase4();
	
	return 0;
}

void inClass()
{
	BinarySearchTree * tree = new BinarySearchTree();
	
	tree->insert(50);
	tree->insert(7);
	tree->insert(3);
	tree->insert(10);
	tree->insert(1);
	tree->insert(346);
	tree->insert(62);
	tree->insert(0);
	
	std::cout << "Root: " << tree->getRoot()->getData() << std::endl;
	
	tree->printTree(tree->getRoot());
	
	delete tree;
}
void phase2()
{
	BinarySearchTree * tree = new BinarySearchTree();
	
	fillTree(tree, "data.txt");
	
	tree->printTree(tree->getRoot());
	
	std::cout << "Root: " << tree->getRoot()->getData() << std::endl;
	
	std::cout << "Heigth: " << tree->getHeight() << std::endl;
	
	delete tree;
}
void phase3()
{
	RedBlackTree * tree = new RedBlackTree();
	
	fillTree(tree, "data.txt");
	
	tree->printTree(tree->getRoot());
	
	std::cout << "Root: " << tree->getRoot()->getData() << std::endl;
	
	std::cout << "Heigth: " << tree->getHeight() << std::endl;
	
	delete tree;
}
void phase4()
{
	RedBlackTree * tree = new RedBlackTree();
	
	fillTree(tree, "data.txt");
	std::cout << "Root: " << tree->getRoot()->getData() << std::endl;
	tree->printTree();
	tree->printBlackNodes(tree->getRoot());
	tree->printRedNodes(tree->getRoot());
	std::cout << std::endl;
	
	delete tree;
	
}


void fillTree(BinarySearchTree * tree, std::string fileName)
{
	//make a fstream object connected to data.txt, then write its contents to the console
	std::ifstream dataIn(fileName);
	int current(0);
	
	while(dataIn >> current)
	{
		tree->insert(current);
	}
}