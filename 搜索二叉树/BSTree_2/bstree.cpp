#define _CRT_SECURE_NO_WARNINGS 1
#include"bstree.hpp"
int main()
{
	Lp700::BSTree<int> bst1;
	bst1.insert(1);
	bst1.insert(2);
	bst1.insert(1);
	std::cout << (bst1.find(2))->data << std::endl;
	
	return 0;
}