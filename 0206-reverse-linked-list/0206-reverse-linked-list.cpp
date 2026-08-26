class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while (curr != nullptr) {
            ListNode *forward = curr->next; 
            curr->next = prev;           
            prev = curr;              
            curr = forward;  
        }
        
        return prev; 
    }
};