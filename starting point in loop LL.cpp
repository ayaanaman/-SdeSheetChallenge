    ListNode *detectCycle(ListNode *head) {
        ListNode *p=head,*q=head;
        
        while(p && p->next)
        {
            q=q->next;
            p=p->next->next;
            if(q==p)
            {
                p=head;
                while(p!=q)
                {
                    p=p->next;
                    q=q->next;
                }
                return p;
            }
        }
        return nullptr;
    }
