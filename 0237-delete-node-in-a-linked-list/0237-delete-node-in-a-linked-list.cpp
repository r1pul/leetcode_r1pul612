/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node->next;

        if (node == nullptr || node->next ==nullptr) {
            return;
        }
        node->val = prev->val;
        node->next = prev->next;
        delete prev;
    }
};