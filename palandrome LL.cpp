    ListNode* tmp;
    
    bool help(ListNode* p)
    {
        if(p==nullptr) return 1;
        bool t=help(p->next) && (p->val == tmp->val);
        tmp=tmp->next;
        return t;
    }
    
    bool isPalindrome(ListNode* head) {
        tmp=head;
        return help(head);
    }
