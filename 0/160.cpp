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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode* cur1, *cur2;
		while(true)
		{
			if(cur1 == cur2)
				break;
			cur1 = cur1? cur1->next: headB;
			cur2 = cur2? cur2->next: headA;
		}
		return cur1;
	}
};