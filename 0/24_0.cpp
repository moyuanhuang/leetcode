/* 24. Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL or head->next == NULL)	return head;
    	ListNode* first = head;
    	ListNode* second = first->next;
    	ListNode* ret = head->next;
        while(1)
        {
        	first->next = second->next;a
        	second->next = first;
        	
            if(first->next == NULL or first->next->next == NULL) return ret;
            ListNode* tmp = first->next;
            first->next = first->next->next;
            first = tmp;
            second = first->next;
        }
        return ret;
    }
};