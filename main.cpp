#include "Node.h"
#include "BST.h"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> list = { 6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99 };
	BST bst = BST();
	bst.MakeBST(list);
	//bst.PrintBST(bst.Root);
	int k = bst.FindKth(4, bst.Root);
	std::cout << "4th element is " << k << std::endl;
}