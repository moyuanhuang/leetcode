#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
	TreeNode* clone(TreeNode* root);
	void visit(int n, std::vector<TreeNode*>& ret, TreeNode* head, TreeNode* cur, int cnt);
	
public:
	Solution()
	{
		std::cout << "initiating Solution..." << std::endl;
	};
	// This is where you define the solution function
	std::vector<TreeNode*> generateTrees(int n);
};
