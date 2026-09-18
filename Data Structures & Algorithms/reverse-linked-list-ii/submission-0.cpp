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
    ListNode *reverse(ListNode *lnode,ListNode *rnode)
    {
        ListNode *curr=lnode;
        ListNode *prev=NULL;
        while(curr!=rnode)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        curr->next=prev;
        prev=curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int l=0;
        int r=0;
        ListNode *curr=head;
        ListNode *lnode=NULL;
        ListNode *rnode=NULL;
        ListNode *lpnode=NULL;
        ListNode *rnnode=NULL;
        while(curr!=NULL)
        {
            l++;
            r++;
            if(l==left-1)
                lpnode=curr;
            if(r==right+1)
                rnnode=curr;
            if(l==left)
                lnode=curr;
            if(r==right)
                rnode=curr;
            curr=curr->next;
        }
        ListNode *nh=reverse(lnode,rnode);
        if(lpnode)
            lpnode->next=nh;
        if(rnnode)
        {
            ListNode *nc=nh;
            ListNode *np=NULL;
            while(nc!=NULL)
            {
                np=nc;
                nc=nc->next;
            }
            np->next=rnnode;
        }
        if(lpnode)
            return head;
        else{
            return nh;
        }    

        
    }
};