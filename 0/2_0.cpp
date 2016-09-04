/*
 * 2. Add two numbers
 * Created by Moyuan Huang on 8.20.2016
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
    	int add_on = 0;
    	ListNode *p1 = l1;
    	ListNode *p2 = l2;
    	while( true )
    	{
    		p1->val += p2->val + add_on;
    		if(p1->val >= 10)
    		{
    			p1->val -= 10;
    			add_on = 1;
    		}
    		else
    		    add_on = 0;
    		if( p1->next == NULL or p2->next == NULL )
    			break;
    		p2 = p2->next;
    		p1 = p1->next;
    	}
    	if( p1->next == NULL)
    	{
    		p2 = p2->next;
    		while( p2 != NULL )
    		{
    			int sum = p2->val + add_on;
    			if( sum >= 10 )
    			{
    				sum -= 10;
    				add_on = 1;
    			}
    			else
    			    add_on = 0;
    			ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    			temp->val = sum;
    			temp->next = NULL;
    			p1->next = temp;
    			cout << temp->val << endl;
    			p1 = p1->next;
    			p2 = p2->next;
    		}
    	}
    	else if( p2->next == NULL)
    	{
    		p1 = p1->next;
    		while( p1 != NULL )
    		{
    			int sum = p1->val + add_on;
    			if( sum >= 10 )
    			{
    				sum -= 10;
    				add_on = 1;
    			}
    			else
    			    add_on = 0;
    			p1->val = sum;
    			if(p1->next == NULL)
    			    break;
    			p1 = p1->next;
    		}
    	}
    	cout << "ok" << endl;
    	if( add_on == 1 )
    	{
    	    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    	    temp->val = 1;
    	    temp->next = NULL;
    	    p1->next = temp;
    	}
    	return l1;
    }
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* t1=l1;
        ListNode* t2=l2;
        t1->val+=t2->val;
        if(t1->val>=10){
            carry=true;
            t1->val-=10;
        }
        while(t1->next!=nullptr){
            t1=t1->next;
            if(t2->next!=nullptr){
                t2=t2->next;
                t1->val+=t2->val;
            }
            if(carry)
                t1->val+=1;
            if(t1->val>=10)
            {
                t1->val-=10;
                carry=true;
            }
            else
                carry=false;
        }
        t1->next=t2->next;
        while(carry){
            if(t1->next==nullptr){
                ListNode *tmp=(ListNode*)malloc(sizeof(ListNode));
                tmp->val=1;
                tmp->next=NULL;
                t1->next=tmp;
                return l1;
            }
            else{
                t1=t1->next;
                t1->val+=1;
                if(t1->val<10)
                    carry=false;
                else
                    t1->val-=10;
            }
        }
        return l1;
    }
    */
};