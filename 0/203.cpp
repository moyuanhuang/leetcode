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
	ListNode* removeElements(ListNode* head, int val)
	{
		if(!head)	return head;
		while(head and head->val == val)	head = head->next;
		ListNode* iter = head;
		ListNode* pre;
		while(iter)
		{
			if(iter->val == val)
			{
				pre->next = iter->next;
				iter = iter->next;
				continue;
			}
			pre = iter;
			iter = iter->next;
		}
		return head;
	}
	
};