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
		if(head == NULL or head->next == NULL)	return head;
		int val = head->val;
		ListNode* p = head->next;
		if(p->val != val)
			head->next = deleteDuplicates(p);
		else
		{
			while(p and p->val == val)	p = p->next;
			return deleteDuplicates(p);
		}
	}
};