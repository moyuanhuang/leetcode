#include "Solution.h"
#include <vector>

using namespace std;

TreeNode* Solution::clone(TreeNode* root)
{
	if(!root)	return NULL;
	TreeNode* newRoot = new TreeNode(root->val);
	newRoot->left = clone(root->left);
	newRoot->right = clone(root->right);
	return newRoot;
}

void Solution::visit(int n, vector<TreeNode*>& ret, TreeNode* head, TreeNode* cur, int cnt)
{
	if(cnt == n)
	{
		TreeNode* newHead = clone(head);
		ret.push_back(newHead);
		return;
	}
	TreeNode* l = new TreeNode(cnt++);
	cur->left = l;
	visit(n, ret, head, cur->left, cnt);
	TreeNode* r = new TreeNode(cnt++);
	cur->right = r;
	visit(n, ret, head, cur->right, cnt);
	cur->left = NULL;
	delete l;
	--(r->val);
	--cnt;
	visit(n, ret, head, cur->right, cnt);
	delete r;
	cur->right = NULL;
	return;
}

vector<TreeNode*> Solution::generateTrees(int n)
{
	vector<TreeNode*> ret;
	int cnt = 0;
	TreeNode* head = new TreeNode(cnt++);
	TreeNode* cur = head;
	visit(n, ret, head, cur, cnt);
	return ret;
}