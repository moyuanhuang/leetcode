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
	ListNode *detectCycle(ListNode *head)
	{
		if(!head)	return head;
		ListNode* fast = head, * slow = head;
		while(fast->next != NULL and fast->next->next != NULL)
		{
			slow = fast->next;
			fast = fast->next->next;
			if(slow == fast)	return slow;
		}
		return NULL;
	}
};