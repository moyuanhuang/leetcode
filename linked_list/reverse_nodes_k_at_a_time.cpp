// leetcode 25. Reverse Nodes in k-Group
// hard
// how to swap the Nodes
// -1 -> 1 -> 2 -> 3 -> 4 -> 5
//  |    |    |
// pre  cur  nex
//
// -1 -> 2 -> 1 -> 3 -> 4 -> 5
//  |         |    |
// pre       cur  nex

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)   return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *cur = dummy, *next = head->next;

        int len = 0;

        while(cur = cur->next){
            len++;
        }
        printf("length of list : %d\n", len);

        for(int idx = 0; idx + k <= len; idx += k){
            // first align the pointer
            cur = prev->next;
            next = cur->next;

            for(int i = 0; i < k - 1; i++){
                ListNode *temp = prev->next;
                prev->next = next;
                cur->next = next->next;
                next->next = temp;

                next = cur->next;
            }
            prev = cur;
        }
        return dummy->next;
    }
};
