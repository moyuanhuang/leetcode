// 445. Add Two Numbers II
// use stack should be the best Solution
// you can also utilize reversing the list

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = nullptr;
        stack<int> s1 = push_to_stack(l1);
        stack<int> s2 = push_to_stack(l2);
        int carry = 0;
        while(!s1.empty() or !s2.empty() or carry){
            int n1 = get_number_from(s1), n2 = get_number_from(s2);
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            temp->next = ret;
            ret = temp;
        }

        return ret;
    }

private:
    stack<int> push_to_stack(ListNode* root){
        ListNode* temp = root;
        stack<int> ret;
        while(temp){
            ret.push(temp->val);
            temp = temp->next;
        }
        return ret;
    }

    int get_number_from(stack<int>& st){
        int ret;
        if(st.empty()){
            ret = 0;
        }else{
            ret = st.top();
            st.pop();
        }
        return ret;
    }
};
