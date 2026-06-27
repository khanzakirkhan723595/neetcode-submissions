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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr=head;
        int n=0;
        while(curr!=NULL && n!=k)
        {
            curr=curr->next;
            n++;
        }
        if(n<k)
        {
            return head;
        }
        ListNode *prev=NULL;
        curr=head;
        n=0;
        while(curr!=NULL && n!=k)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            n++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
        
        
    }
};
