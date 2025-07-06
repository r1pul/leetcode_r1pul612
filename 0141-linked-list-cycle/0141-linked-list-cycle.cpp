class Solution {
public:
    bool hasCycle(ListNode *head) {
     if(head==NULL || head->next == NULL)
     return false;
     ListNode *s = head;
     ListNode *f=head->next;
      while (f != NULL && f->next != NULL)
     {
        if(f->next != NULL || f->next->next != NULL){
        s=s->next;
        f=f->next->next;
        }
        if(s==f)
            return true;
        
     }
     return false;   
    }
};
