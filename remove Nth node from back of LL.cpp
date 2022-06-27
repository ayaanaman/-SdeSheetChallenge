    ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *p=head,*q=head,*r=NULL;
    while(n-- && p)
        p=p->next;
    
    if(!p) return head->next;
    
    while(p)
    {
        r=q;
        q=q->next;
        p=p->next;
    }
    r->next=q->next;
    return head;
}
