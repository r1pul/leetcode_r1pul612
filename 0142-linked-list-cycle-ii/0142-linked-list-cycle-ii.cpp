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
    ListNode* detectCycle(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        if (head == NULL || head->next == NULL)
            return NULL;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f)
                break;
        }
        ListNode* p = head;
        if (s != f)
            return NULL;

        while (p != s) {
            p = p->next;
            s = s->next;
        }
        return s;
    }
};