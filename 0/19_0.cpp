/* 19. Remove Nth Node From End of List
 * Created Moyuan Huang on Sep.4, 2016.
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode*> listVec;
		listVec.push_back(head);
		ListNode* ptr = head;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
			listVec.push_back(ptr);
		}
		int len = listVec.size();
		if(n > len or n <= 0)	return head;
		else if(n == len)	return head->next;
		else if(n == 1)	listVec[len - 2]->next = NULL;
		else
			listVec[len - n - 1]->next = listVec[len - n + 1];
		return head;

	}
};
/*
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode* dummy(-1);
		dummy->next = head;
		ListNode* ptr1 = dummy;
		ListNode* ptr2 = head;
		while(n>0)
		{
			ptr2 = ptr2->next;
			n--;
		}
		while(ptr2 != NULL)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		ptr1->next = ptr->next->next;
		return head;
	}
*/