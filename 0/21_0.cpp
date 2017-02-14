/* 21. Merge Two Sorted Lists
 * Created by Moyuan Huang on Sep.4, 2016.
*/
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1)	return l2;
		if(!l2)	return l1;

		ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
		ListNode* ptr1 = l1;
		ListNode* ptr2 = l2;
		ListNode* ptrr = ret;
		while(ptr1 != NULL and ptr2 != NULL)
		{
			if(ptr1->val <= ptr2->val)
			{
				ptrr->next = ptr1;
				ptr1 = ptr1->next;
			}
			else
			{
				ptrr->next = ptr2;
				ptr2 = ptr2->next;
			}
			ptrr = ptrr->next;
		}
		if(!ptr1)	ptrr->next = ptr2;
		else if(!ptr2)	ptrr->next = ptr1;
		return ret->next;

	}
};