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
	ListNode* partition(ListNode* head, int x)
	{
		if(!head or !head->next)	return head;
		ListNode* start = head;
		ListNode* end = head->next;		
		while(start!= NULL)
		{
			while(start and start->val < x)	start = start->next;
			end = start;
			while(end and end->val > x) end = end->next;
			if(!start or !end)
				break;
			int temp = start->val;
			start->val = end->val;
			end->val = temp;
			start = start->next;
		}
		return head;
	}
};