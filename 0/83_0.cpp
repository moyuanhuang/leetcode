/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if(!head or !head->next)	return head;
		ListNode* prev = head;
		ListNode* cur = head->next;
		while(cur)
		{
			if(prev->val == cur->val)
			{
				prev->next = cur->next;
				cur = prev->next;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		return head;
	}
};