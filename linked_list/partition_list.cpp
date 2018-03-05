// 86. Partition list
// medium
// we need to find the FIRST cur->val >= x!, else the main while loop won't work
// for example,   [1,1,1,3,2]
//              |  |
//           prev cur

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
    ListNode* partition(ListNode* head, int x) {
        if(!head)    return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        while(cur and cur->val < x){
            prev = cur;
            cur = cur->next;
        }
        ListNode *front = prev;
        while(cur){
            if(cur->val < x){
                prev->next = cur->next;
                cur->next = front->next;
                front->next = cur;

                cur = prev->next;
                front = front->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
