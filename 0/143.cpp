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
	void reorderList(ListNode* head)
	{
		ListNode* h, *t;
		while(t->next)	t = t->next;
		ListNode* tmp = t;
		while(h->next != t)
		{
			tmp->next = h->next;
			tmp = tmp->next;
			h->next = tmp->next;
		}
	}
};