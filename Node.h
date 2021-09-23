#pragma once
class Node
{
public:
	Node();
	Node(int Key, Node* Left, Node* Right);

	int Key;
	Node* Left;
	Node* Right;
};

