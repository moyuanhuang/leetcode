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
	bool isPalindrome(ListNode* head)
	{
		ListNode* fast = head, * slow = head;
		ListNode* prev = NULL, next;
		while(fast->next)
		{
			fast = fast->next;

			next = slow->next;
			slow->next = prev;
			prev = slow;
			slow = next;

			if(fast->next)
				fast = fast->next;
		}
		ListNode* p1 = prev, p2 = slow;
		while(p1 and p2)
		{
			if(p1->val != p2->val)	return false;
			p1= p1->next;
			p2= p2->next;
		}
		return true;
	}
};
