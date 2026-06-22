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
    //     // Reverse list
    // ListNode* prev = NULL;
    // ListNode* curr = head;

    // while(curr)
    // {
    //     ListNode* next = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = next;
    // }

    // // Remove nth node from start of reversed list
    // if(n == 1)
    // {
    //     ListNode* temp = prev;
    //     prev = prev->next;
    //     delete temp;
    // }
    // else
    // {
    //     curr = prev;

    //     for(int i = 1; i < n - 1; i++)
    //     {
    //         curr = curr->next;
    //     }

    //     curr->next = curr->next->next;
    // }

    // // Reverse again
    // curr = prev;
    // prev = NULL;

    // while(curr)
    // {
    //     ListNode* next = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = next;
    // }

    // return prev;


    //method 2
    ListNode dummy(0);
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}

};
