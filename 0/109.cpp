/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		if(!head)	return NULL;
		return helper(head, NULL);
	}

	TreeNode* helper(TreeNode* head, TreeNode* tail)
	{
		TreeNode* slow = head;
		TreeNode* fast = head;
		if (head == tail)	return NULL;

		while(fast!= tail and fast->next != tail)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow.val);
		root->left = helper(head, slow);
		root->right = helper(slow->next, tail);
		return root;
	}
};