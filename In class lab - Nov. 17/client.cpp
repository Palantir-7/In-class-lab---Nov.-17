//Elizabeth Fanton 11/17/26
// code was updated on 11/17/26
//In class lab - Nov. 17
#include"BinaryTree.h"

int main()
{
	BinaryTree binaryTree('a');
	binaryTree.addData('b');
	binaryTree.addData('c');
	binaryTree.addData('d');
	binaryTree.addData('e');

	Node* root = binaryTree.getRoot();

	binaryTree.addData('f');

	binaryTree.breadthFirstTraverse();

	binaryTree.print(binaryTree.getRoot());

	//binaryTree.depthFirstTraverse();
}