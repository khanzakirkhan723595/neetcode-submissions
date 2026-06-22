class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* curr = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Merge
        ListNode* first = head;
        ListNode* second = prev;

        while(second)
        {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};