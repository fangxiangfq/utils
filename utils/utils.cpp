#include <iostream>
#include "binary_tree.h"
#include "algorithm.h"
#include "sort.h"

using namespace utils;

int main()
{
	//std::vector<int> v{ 1, 2, -1, -1, 3, 4, 5, -1, 6, -1, -1, 7, 8 };
	//auto it = v.begin();
	//auto root = createBinaryTree(it, v.end(), -1);
	//auto ret = levelOrderTraverse(root);
	//for (auto lv : ret) {
	//	for (auto it : lv) {
	//		std::cout << it << " ";
	//	}

	//	std::cout << std::endl;
	//}

	//std::vector<int> ans;
	//postorderTraverse_Iterative(root, ans);

	//distroyBinaryTree(root);

	std::vector<int> v{ 1, 2, 3, 4, 5, 6, -1, -1, 7, 8 };
	print(v.begin(), v.end());
	heap_sort(v.begin(), v.end());
	print(v.begin(), v.end());
}

