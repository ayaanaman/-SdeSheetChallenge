    ListNode* middleNode(ListNode* head) {
        ListNode *p=head, *q=head;
        
        while(p && p->next)
        {
            p=p->next;
            q=q->next;
            if(p)
                p=p->next;
        }
        return q;
    }
