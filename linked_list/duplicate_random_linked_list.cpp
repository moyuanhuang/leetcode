// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=311867&highlight=bloomberg
// on campus
// leetcode 138. Copy List with Random Pointer

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *root) {
        if(!root)   return root;
        RandomListNode* iter = root;

        while(iter){
            cout << "1" << endl;
            RandomListNode* new_node = new RandomListNode(iter->label);
            RandomListNode* next = iter->next;
            iter->next = new_node;
            new_node->next = next;
            iter = new_node->next;
        }

        iter = root;
        while(iter){
            cout << "2" << endl;
            RandomListNode* shadow = iter->next;
            if(iter->random)
                shadow->random = iter->random->next;
            iter = iter->next->next;
        }

        iter = root;
        RandomListNode* head = iter->next;
        while(true){
            RandomListNode* shadow = iter->next;
            RandomListNode* next = shadow->next;
            if(!next){
                iter->next = NULL;
                break;
            }
            iter->next = next;
            shadow->next = next->next;

            iter = next;
        }

        return head;
        }
};
