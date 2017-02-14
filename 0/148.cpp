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
	ListNode* sortList(ListNode* head) {
		return helper(head);
	}

	ListNode* helper(ListNode* head)
	{
		if(!haed or !head->next)
			return head;
		ListNode* fast = head, slow = head;
		while(fast->next)
		{
			fast = fast->next;
			if(!fast->next)
				break;
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* right = slow->next, left = head;
		slow->next = NULL;
		right = helper(right);
		left = helper(left);
		return merge(left, right);
	}
	ListNode* merge(ListNode* left, ListNode* right)
	{
		ListNode* head = new ListNode(-1);
		while(left or right)
		{
			if(!right or (left and (left->next < right->next)))
			{
				head->next = left;
				left = left->next;
			}
			else
			{
				head->next = right;
				right= right->next;
			}
			head = head->next;
		}
		return head->next;
	}
};