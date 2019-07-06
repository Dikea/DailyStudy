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
    void reorderList(ListNode* head) {
        if(!head || !head->next) 
            return ;
        
        # Find mid node.
        ListNode *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        # Reverse the post part.
        ListNode* p = slow->next;
        ListNode* pre;
        pre = NULL;
        while(p) {
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        
        # Merget first part and last part.
        p = head;
        ListNode* q = pre;
        slow->next = NULL;
        while(p && q) {
            ListNode *pnext = p->next;
            ListNode *qnext = q->next;
            p->next = q;
            p->next->next = pnext;
            p = pnext;
            q = qnext;
        }
        
    }
};
