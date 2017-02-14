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
	bool hasCycle(ListNode *head)
	{
		if(!head)	return false;
		ListNode* walker = head, runner = head;
		while(walker->next != NULL and runner->next->next != NULL)
		{
			walker = walker->next;
			runner = runner->next->next;
			if(walker == runner)	return true;
		}
		return false;
	}
};