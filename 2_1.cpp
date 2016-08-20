/*
 * 2. Add two numbers
 * Created by Moyuan Huang on 8/20/2016
*/
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    	// first, consider the NULL list cases
    	if(l1 and l2 == NULL)	return l1;
    	if(l1 == NULL and l2)	return l2;
    	if(l1 == NULL and l2 == NULL)	return NULL;

    	// take l1 and l2 as two resources pool
    	ListNode *p1 = l1;
    	ListNode *p2 = l2;
    	ListNode *pr = l1;
    	ListNode *result = *pr;
    	bool isUsingl2 = false;

    	int carry = 0;
    	while( p1 || p2 || carry )
    	{
    		int sum = carry;
    		if(p1)	sum += p1->val;
    		if(p2)	sum += p2->val;
    		carry = sum >= 10? 1:0;
    		r->val = sum % 10;

    		if(p1)	p1->next;
    		if(p2)	p2->next;

    		if(not isUsingl2 and r->next == NULL)
    		{
    			r->next = l2;
    			isUsingl2 = false;
    		}

    		if( p1 || p2 || carry )
    			r = r->next;
    	}
    	r->next == NULL;

        return result;
    }
};
