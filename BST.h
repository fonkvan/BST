#pragma once
#include <vector>

class Node;
class BST
{
public:
	BST();
	Node* MakeBST(std::vector<int> list);
	void PrintBST(Node* Node);
	int FindKth(int k, Node* node, bool SolFound = false);
	Node* Root;
};

