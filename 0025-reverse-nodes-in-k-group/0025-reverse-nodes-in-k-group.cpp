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
    ListNode* reverse(ListNode* temp) {
        ListNode* p = nullptr;
        ListNode* c = temp;
        while (c) {
            ListNode* r = c->next;
            c->next = p;
            p = c;
            c = r;
        }
        return p;
    }
    ListNode* kth(ListNode* temp, int rk) {
        rk -= 1;
        while (temp && rk > 0) {
            rk--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            int rk = k;
            ListNode* k = kth(temp, rk);
            if (k == nullptr) {
                if (prev)
                    prev->next = temp;

                break;
            }
            ListNode* next = k->next;
            k->next = nullptr;
            reverse(temp);
            if (temp == head)
                head = k;
            else
                prev->next = k;

            prev = temp;
            temp = next;
        }
        return head;
    }
};