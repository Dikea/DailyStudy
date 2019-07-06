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
        stack<int> st1, st2;
        while(l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int val = 0;
        ListNode* res;
        ListNode *pre, *p;
        pre = NULL;
        while(!st1.empty() || !st2.empty() || val) {
            if(!st1.empty()) {
                val += st1.top();
                st1.pop();
            }
            if(!st2.empty()) {
                val += st2.top();
                st2.pop();
            }
            res = new ListNode(val % 10);
            val /= 10;
            res->next = pre;
            pre = res;
        }
        return res;
    }
};
