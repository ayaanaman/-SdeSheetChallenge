    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *r=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return r;
    }
