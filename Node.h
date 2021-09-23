#pragma once
class Node
{
public:
	Node();
	Node(int Key, Node* Left, Node* Right, Node* Parent = nullptr);

	int Key;
	Node* Left;
	Node* Right;
	Node* Parent;
};

