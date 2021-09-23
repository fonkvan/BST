#include "Node.h"

Node::Node()
{
	Key = 0;
	Left = nullptr;
	Right = nullptr;
}

Node::Node(int Key, Node* Left, Node* Right)
{
	this->Key = Key;
	this->Left = Left;
	this->Right = Right;
}