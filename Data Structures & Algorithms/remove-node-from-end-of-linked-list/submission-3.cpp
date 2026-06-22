/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==1 && head->next==NULL)
        {
            return NULL;
        }
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL)
        {
            ListNode *t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        int k=1;
        ListNode *curr=prev;
        ListNode *prv=NULL;
        while(k!=n && curr!=NULL)
        {
            k++;
            prv=curr;
            curr=curr->next;
            
        }
        if(n==1)
        {
            prev=prev->next;
        }
        if(k==n && n!=1)
            {
                if(curr->next!=NULL)
                {
                    prv->next=curr->next;
                    

                }
                else{
                    prv->next=NULL;
                    
                }
            }
        if(curr==NULL && k!=n)
        {
            return head;
        }

        ListNode *temp1=prev;
        ListNode *prev1=NULL;
        while(temp1!=NULL)
        {
            ListNode *t=temp1->next;
            temp1->next=prev1;
            prev1=temp1;
            temp1=t;
        }
        return prev1;

        
    }
};
