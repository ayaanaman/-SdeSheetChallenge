    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head,*p;
        int carry=0;
        
        head=new ListNode((l1->val + l2->val + carry)%10);
        p=head;
        carry=(l1->val + l2->val + carry)/10;
        l1=l1->next;
        l2=l2->next;
        
        while(l1 && l2)
        {
            p->next=new ListNode((l1->val + l2->val + carry)%10);
            p=p->next;
            carry=(l1->val + l2->val + carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1)
        {
            p->next=new ListNode((l1->val + carry)%10);
            p=p->next;
            carry=(l1->val + carry)/10;
            l1=l1->next;
        }
        
        while(l2)
        {
            p->next=new ListNode((l2->val  + carry)%10);
            p=p->next;
            carry=(l2->val + carry)/10;
            l2=l2->next;
        }
        
        if(carry != 0)
           p->next=new ListNode(carry);
        return head;
    }
