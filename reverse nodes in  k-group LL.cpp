/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* help(ListNode *head, int k, int nodes)
    {
        if(!head || !head->next || nodes<k) return head;
        
        ListNode *p,*q=head,*r=NULL;
        p=q;
        
        int n=k;
        while(n--)
            p=p->next;
        
        r=help(p,k,nodes-k);
        
        p=q->next;
        
        while(k--)
        {
            if(q)
                q->next=r;
            r=q;
            q=p;
            if(p)
                p=p->next;
        }
        
        return r;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int nodes=0;
        ListNode *p=head;
        while(p)
        {
            p=p->next;
            nodes++;
        }
        
        cout<<nodes;
        
        if(nodes<k)
            return head;
        
        return help(head,k,nodes);
    }
};
