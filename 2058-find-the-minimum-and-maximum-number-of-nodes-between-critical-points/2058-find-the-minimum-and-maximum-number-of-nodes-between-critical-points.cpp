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
        
        int pos = 1;
        int first = -1;
        int prev = -1;
        int minDist = INT_MAX;
        
        ListNode* prevNode = head;
        ListNode* curr = head->next;
        
        while (curr != nullptr && curr->next != nullptr) {
            
            ListNode* nextNode = curr->next;
            
            // Check whether curr is a critical point
            if ((curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val)) {
                
                // First critical point
                if (first == -1) {
                    first = pos;
                }
                
                // We already have a previous critical point
                if (prev != -1) {
                    minDist = min(minDist, pos - prev);
                }
                
                prev = pos;
            }
            
            prevNode = curr;
            curr = curr->next;
            pos++;
        }
        
        // Fewer than two critical points
        if (first == -1 || prev == first) {
            return {-1, -1};
        }
        
        int maxDist = prev - first;
        
        return {minDist, maxDist};
    }
};