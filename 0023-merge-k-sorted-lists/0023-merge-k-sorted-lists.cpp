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
ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
        return NULL;
    }
ListNode* partation(int s, int e, vector<ListNode*>& lists) {
        if (s > e)
            return nullptr;

        if (s == e)
            return lists[s];

        int mid = s + (e - s) / 2;

        ListNode* l1 = partation(s, mid, lists);
        ListNode* l2 = partation(mid + 1, e, lists);
        return merge(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        int s = 0;
        
        if(k==0)
        return nullptr;
        return partation(s, k-1, lists);
    }
    
    
};