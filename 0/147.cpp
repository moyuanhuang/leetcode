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
	ListNode* insertionSortList(ListNode* head)
	{
		if(!head)	return head;
		ListNode* pre1 = NULL;
		for(ListNode* i = head; i != NULL; pre1 = i, i = i->next)
		{
			ListNode max = i, pre2 = NULL;
			for(ListNode* j = i->next; j != NULL; pre2 = j, j = j->next)
			{
				if(max->val <= j->val)
				{
					max = j;
				}
				if(pre2)	pre2->next = i;
				if(pre1)	pre1->next = max;
				ListNode* tmp = max->next;
				max->next = i->next;
				i->next = tmp;
			}
		}
	}
};