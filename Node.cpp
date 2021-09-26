#include "Node.h"

Node::Node()
{
	Key = 0;
	Left = nullptr;
	Right = nullptr;
	Parent = nullptr;
}

Node::Node(int Key, Node* Left, Node* Right, Node* Parent)
{
	this->Key = Key;
	this->Left = Left;
	this->Right = Right;
	this->Parent = Parent;
}