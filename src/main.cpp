// https://leetcode.com/problems/binary-tree-right-side-view/

#include<iostream>
#include"../inc/solution.hpp"


void PrintVec(std::vector<int>&& vec)
{
	for(int i : vec){ std::cout << i << ' '; }
	std::cout << '\n';
}

int main()
{
	TreeNode n5(5);
	TreeNode n4(4);
	TreeNode n3(3, nullptr, &n4);
	TreeNode n2(2, nullptr, &n5);
	TreeNode root(1, &n2, &n3);

	TreeNode m5(5);
	TreeNode m3(3, nullptr, nullptr);
	TreeNode m2(2, nullptr, &m5);
	TreeNode root2(1, &m2, &m3);

	PrintVec(Solution().rightSideView(&root));  // {1,3,4}
	PrintVec(Solution().rightSideView(&root2));  // {1,3,5}
	return 0;
}

