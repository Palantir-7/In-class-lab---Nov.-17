#include "BinaryTree.h"
#include <iostream>

Node::Node() = default;

Node::Node(char data)
	:
	data(data), pleft(nullptr), pright(nullptr)
{

}

BinaryTree::BinaryTree() = default;
//{
//	pRoot = nullptr;
//}

BinaryTree::BinaryTree(char dataInTheRoot)
{
	pRoot = make_unique<Node>(dataInTheRoot);
}

void BinaryTree::addData(char newData) const
{
	unique_ptr<Node> pNew = make_unique<Node>(newData);

	queue<Node*> q;

	q.push(pRoot.get());

	bool wasDataAdded = false;

	while (!wasDataAdded && q.empty() == false)
	{
		std::unique_ptr<Node> pNew = make_unique<Node>(newData);

		Node* pCurrent = q.front();
		if (!pCurrent->pleft)//means pLeft == nullptr
		{
			pCurrent->pleft = move(pNew);
			q.push(pCurrent->pleft.get());
			wasDataAdded = true;
		}
		else if (!pCurrent->pright)
		{
			q.push(pCurrent->pright.get());

			pCurrent->pright = move(pNew);
			wasDataAdded = true;
		}
		//else//bothe the left and right spots are occupied - move down one
		//{
		//}
	}
	//if (pRoot->pleft == nullptr)
	//{
	//	pRoot->pleft = move(pNew);
	//}
	//else if (pRoot->pright == nullptr)
	//{
	//	pRoot->pright = move(pNew);
	//}
	////second level
	//else if
	//	(pRoot->pleft->pleft == nullptr)
	//{
	//	pRoot->pleft->pleft = move(pNew);
	//}
	//else if
	//	(pRoot->pleft->pright == nullptr)
	//{
	//	pRoot->pleft->pright = move(pNew);
	//}
}

void BinaryTree::print(Node* pCurrent) const
{
	//base case (termination) of recursion
	if (pCurrent == nullptr)
	{
		return;
	}
	cout << pCurrent->data << endl;
	print(pCurrent->pleft.get());//recurse
	print(pCurrent->pright.get());

}

Node* BinaryTree::getRoot() const
{
	return pRoot.get();
}

void BinaryTree::breadthFirstTraverse() const
{
	//queue to the res-cue
	std::queue<Node*> q;

	q.push(pRoot.get());

	while (q.empty() == false)
	{
		Node* pCurrent = q.front();
		
		std::cout << pCurrent->data << std::endl;

		q.pop();

		if (pCurrent->pleft)
		{
			q.push(pCurrent->pleft.get());
		}

		if (pCurrent->pright)
		{
			q.push(pCurrent->pright.get());
		}
	}
}

