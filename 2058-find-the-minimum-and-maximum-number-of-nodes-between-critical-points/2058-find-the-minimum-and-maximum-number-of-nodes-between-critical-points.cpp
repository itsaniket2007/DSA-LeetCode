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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        int firstIndex = -1;
        int prevIndex = -1;
        int minDistance = INT_MAX;
        int maxDistance = -1;
        int currIdx = 2;
        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (firstIndex == -1) {
                    firstIndex = currIdx;
                    prevIndex = currIdx;
                } else {
                    minDistance = min(minDistance, currIdx - prevIndex);
                    prevIndex = currIdx;
                    maxDistance = prevIndex - firstIndex;
                }
            }    
            prev = curr;
            curr = curr->next;
            currIdx++;
        }  
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }
        return {minDistance, maxDistance};
    }
};