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
	Root = new Node(Key, MakeBST(left), MakeBST(right), Root);
	return Root;
}

int BST::FindKth(int k, Node* node, bool SolFound)
{
	node->Parent = node;
	int count = 0;
	int Key = 0;
	Node NodeToDelete = Node();
	while (!SolFound)
	{
		if (node->Left == nullptr && node->Right == nullptr)
		{
			NodeToDelete = *node;
			node = node->Parent;
			if (NodeToDelete.Key == node->Left->Key)
			{
				node->Left = nullptr;
				++count;
				if (count == k)
				{
					Key = node->Key;
					SolFound = true;
				}
				node = Root;
			}
			if (NodeToDelete.Key == node->Right->Key)
			{
				node->Right = nullptr;
				++count;
				if (count == k)
				{
					Key = node->Key;
					SolFound = true;
				}
				node = Root;
			}
		}
		else if (node->Left != nullptr)
		{
			node = node->Left;
		}
		else if (node->Right != nullptr)
		{
			node = node->Right;
		}
	}
	return Key;
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