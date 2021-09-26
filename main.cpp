#include "Node.h"
#include "BST.h"
#include <vector>
#include <iostream>
#define MAX 15
int main()
{
	std::vector<int> list = { 6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99 };
	BST bst = BST();
	bst.MakeBST(list);
	bst.PrintBST(bst.Root, 1);
	std::cout << "What smallest element k would you like to search for?" << std::endl;
	int k;
	bool bValid = false;
	while (!bValid)
	{
		std::cin >> k;
		if (k <= 0 || k > 15 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\nYou did not enter a valid number please try again\n";
		}
		else
		{
			bValid = true;
		}
	}
	int element = bst.FindKth(k);
	std::cout << "Your element is " << element << std::endl;
}