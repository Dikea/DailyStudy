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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode *res = new ListNode(0);
        while(head) {
            ListNode* p = res->next;
            ListNode* pre = res;
            while(p && head->val > p->val) {
                pre = p;
                p = p->next;
            }
            pre->next = new ListNode(head->val);
            pre = pre->next;
            pre->next = p;
            head = head->next;
        }
        return res->next;
    }
};
