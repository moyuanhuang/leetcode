/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct comparator{
  bool operator()(ListNode* left, ListNode* right){
    return left->val > r->val;
  }
}

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummy(-1);
    priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
    for(ListNode* list in lists){
      pq.push(list);
    }
    ListNode head = dummy;
    while(!pq.empty()){
       ListNode* temp = pq.pop();
       head->next = temp;
       if(temp->next) pq.push(temp->next);
    }
    return dummy->next;
  }
};
