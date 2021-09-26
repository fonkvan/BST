#include "BST.h"
#include "Node.h"
#include <iostream>

BST::BST()
{
	Root = nullptr;
}

//this initializes the tree
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

//I was struggling to find the kth element through the tree itself, so I ended up making a stack here
int BST::FindKth(int k)
{
	MakeStack(Root);
	int Sol = 0;
	while (!Nodes.empty())
	{
		if (Nodes.size() == k)
		{
			Sol = Nodes.top()->Key;
			return Sol;
		}
		Nodes.pop();
	}
}

//I originally wanted to print it vertically, and was able to just not in the right order
//so i went with a method to print the tree horizontally, pretty much just changes
//the amount of spaces before the number at each depth to give it the tree like effect
void BST::PrintBST(Node* Node, int spaces)
{
	if (Node == nullptr)
	{
		return;
	}
	spaces = spaces<<1;
	PrintBST(Node->Right, spaces);
	int count = spaces;
	while (count != 0)
	{
		std::cout << " ";
		--count;
	}
	std::cout << Node->Key << std::endl;
	PrintBST(Node->Left, spaces);
}

//Makes stack using in order traversal
void BST::MakeStack(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	MakeStack(node->Left);
	Nodes.push(node);
	MakeStack(node->Right);
}