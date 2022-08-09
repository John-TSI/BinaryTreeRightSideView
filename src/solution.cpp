#include<queue>
#include"../inc/solution.hpp"


std::vector<int> Solution::rightSideView(TreeNode* root)
{
    std::vector<int> visibleValues{};
    std::queue<TreeNode*> nodes{};

    if(!root){ return visibleValues; }  // handle empty tree
    nodes.push(root);

    while(!nodes.empty())
    {
        // implement a breadth-first tree search, at each level the visible node is the rightmost.
        visibleValues.push_back(nodes.back()->val);  // rightmost node per level is the most recently added to queue

        int nodesOnThisLevel = nodes.size();  // initially one for root, then recomputed each loop iteration
        for(int i{0}; i<nodesOnThisLevel; ++i)
        {
            // left child nodes are pushed onto the queue before right child nodes;
            // on each level, the 'visible' node is the rightmost child of the rightmost node of the previous level
            if(nodes.front()->left){ nodes.push(nodes.front()->left); }
            if(nodes.front()->right){ nodes.push(nodes.front()->right); } 
            nodes.pop(); 
        }
    }
    return visibleValues;
}