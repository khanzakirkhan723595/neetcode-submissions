class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode *s=head;
        ListNode *f=head;
        while(f!=NULL && f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        ListNode *temp=s->next;
        s->next=NULL;
        ListNode *prev=NULL;
        while(temp!=NULL)
        {
            ListNode *t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        ListNode *curr=head;
        while(curr!=NULL && prev!=NULL)
        {
            ListNode *temp1=curr->next;
            curr->next=prev;
            curr=temp1;
            ListNode *temp2=prev->next;
            prev->next=curr;
            prev=temp2;
        }
    }
};