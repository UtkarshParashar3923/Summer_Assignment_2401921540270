class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;   // store next node
            curr->next = prev;   // reverse link
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }

        return prev;
    }
};
