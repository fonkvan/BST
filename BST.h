#pragma once
#include <vector>
#include <stack>

class Node;
class BST
{
public:
	BST();
	Node* MakeBST(std::vector<int> list);
	void PrintBST(Node* Node, int spaces);
	int FindKth(int k);
	void MakeStack(Node* node);
	Node* Root;
	std::stack<Node*> Nodes;
};

