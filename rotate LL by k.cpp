class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int nodes=0;
        
        ListNode*p=head;
        
        while(p)
        {
            p=p->next;
            nodes++;
        }
        
        if(k==0 || nodes<2)
            return head;
        
        k=k%nodes;
        
        if(k==0)
            return head;
        
        ListNode *q=head;
        p=head;
        
        while(k--)
            p=p->next;
        
        while(p->next)
        {
            q=q->next;
            p=p->next;
        }
        ListNode *newhead=q->next;
        q->next=NULL;
        p->next=head;
        return newhead;
        
    }
};
