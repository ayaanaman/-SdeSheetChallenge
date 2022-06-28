    bool hasCycle(ListNode *head) {
     
        ListNode *p=head,*q=head;
        
        do
        {
            if(q)
                q=q->next;
            if(p)
                p=p->next;
            if(p)
                p=p->next;
        }while(p!=q && p && q);
        
        if(!p || !q) return false;
        return true;
    }
