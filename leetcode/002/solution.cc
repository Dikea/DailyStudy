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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* p = res;
        int val = 0;
        while(l1 || l2 || val) {
            if(l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                val += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(val % 10);
            p = p->next;
            val = val / 10;
        }
        return res->next;
    }
};
