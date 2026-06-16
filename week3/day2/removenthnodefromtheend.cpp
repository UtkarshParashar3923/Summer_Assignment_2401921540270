class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node pointing to head (to handle edge cases)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // First and second pointers
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;

        
        delete nodeToDelete;

       
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
