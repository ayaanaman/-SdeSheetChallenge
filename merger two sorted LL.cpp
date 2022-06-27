    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* p=nullptr,*head=list2;
        
        while(list1 && list2)
        {
            if(list1->val<=list2->val)
            {
                ListNode *tmp=list1;
                list1=list1->next;
                
                if(p)
                    p->next=tmp;
                else
                {
                    head=tmp;
                }
                p=tmp;
                tmp->next=list2;
            }
            else
            {
                p=list2;
                list2=list2->next;
            } 
        }
        
        if(list1)
        {
            if(p)
                p->next=list1;
            else
                head=list1;
        }
        
        return head;
    }
