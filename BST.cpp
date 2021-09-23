#include "BST.h"
#include "Node.h"
#include <iostream>

BST::BST()
{
	Root = nullptr;
}

Node* BST::MakeBST(std::vector<int> list)
{
	std::vector<int> left;
	std::vector<int> right;
	if (list.empty())
	{
		return nullptr;
	}
	int HalfSize = list.size()/2;
	int Key = list[HalfSize];
	for (int i = 0; i < HalfSize; ++i)
	{
		left.push_back(list[i]);
		right.push_back(list[i+HalfSize+1]);
	}
	Root = new Node(Key, MakeBST(left), MakeBST(right));
	return Root;
}

int BST::FindKth(int k, Node* Node, bool SolFound)
{
	int count = 0;
	int key = 0;
	if (k == count)
	{
		SolFound = true;
		key = Node->Key;
		return key;
	}
	if (Node == nullptr)
	{
		return 0;
	}
	if (Node != nullptr)
	{
		++count;
		FindKth(k, Node->Left);
		if (SolFound)
		{
			return key;
		}
		++count;
		FindKth(k, Node->Right);
		if (SolFound)
		{
			return key;
		}
	}
}

void BST::PrintBST(Node* Node)
{
	if (Node == nullptr)
	{
		return;
	}
	PrintBST(Node->Left);
	std::cout << Node->Key << std::endl;
	PrintBST(Node->Right);
}