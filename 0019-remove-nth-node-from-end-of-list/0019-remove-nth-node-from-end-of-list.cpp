class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            temp = temp->next;
            count++;
        }
        int target = count - n;
        ListNode* curr = dummy;
        for (int i = 0; i < target; i++) {
            curr = curr->next;
        }
        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;       
        ListNode* newHead = dummy->next;
        delete dummy;      
        return newHead;
    }
};