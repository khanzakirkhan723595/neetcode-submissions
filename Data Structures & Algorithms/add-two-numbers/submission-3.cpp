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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *prev=NULL;
    ListNode *h1=l1;
    ListNode *h2=l2;

    int q=0;

    while(h1!=NULL && h2!=NULL)
    {
        int sum = h1->val + h2->val + q;

        h1->val = sum % 10;

        q = sum / 10;

        prev = h1;

        h1 = h1->next;
        h2 = h2->next;
    }

    if(h2!=NULL && h1==NULL)
    {
        prev->next=h2;

        while(h2!=NULL)
        {
            int sum = h2->val + q;

            h2->val = sum % 10;

            q = sum / 10;

            prev = h2;
            h2 = h2->next;
        }
    }

    if(h2==NULL && h1!=NULL)
    {
        while(h1!=NULL)
        {
            int sum = h1->val + q;

            h1->val = sum % 10;

            q = sum / 10;

            prev = h1;
            h1 = h1->next;
        }
    }

    if(q!=0)
    {
        prev->next = new ListNode(q);
    }

    return l1;
}
};
