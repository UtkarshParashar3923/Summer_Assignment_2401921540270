class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;

      
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

       
        slow = reverse(slow);

     
        ListNode* temp = head;
        while(slow != NULL){
            if(temp->val != slow->val)
                return false;

            temp = temp->next;
            slow = slow->next;
        }

        return true;
    }
};
