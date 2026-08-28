class Solution {
public:
    int size_node(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head ;
        int n = size_node(head);
        int target = n / 2 - 1;
        for (int i = 0; i < target; i++) {
        slow = slow->next;
        }
        ListNode* Temp = slow->next;
        slow->next = slow->next->next;
        delete Temp;
        return head;
    }
};