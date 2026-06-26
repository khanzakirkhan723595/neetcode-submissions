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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        ListNode dummy(0);
        ListNode *tail=&dummy;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        
        if(list1 != NULL)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }
        return dummy.next;
        
    }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if(lists.size()==0 || lists[0]==NULL)
    //     {
    //         return NULL;
    //     }
    //     ListNode* temp=lists[0];
        
    //     for(int i=1;i<lists.size();i++)
    //     {
    //         temp=mergeTwoLists(temp,lists[i]);

    //     }
    //     return temp;
        
    // }


    //method 2
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    int n = lists.size();

    if(n == 0)
        return NULL;

    int interval = 1;

    while(interval < n)
    {
        for(int i = 0; i + interval < n; i += interval * 2)
        {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }

        interval *= 2;
    }

    return lists[0];
}
};
