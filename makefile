A5.exe: TreeNode.o BinarySearchTree.o RedBlackTree.o driver.o
	g++ TreeNode.o BinarySearchTree.o RedBlackTree.o driver.o -o Tree.exe

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

clean:
	rm *.o *.exe

run:
	clear
	make
	Tree.exe

runv:
	clear
	make
	valgrind --log-file="valgrind.txt" --leak-check=full -s Tree.exe