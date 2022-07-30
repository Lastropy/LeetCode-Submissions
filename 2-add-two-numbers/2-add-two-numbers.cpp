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
    int len(ListNode *t){
        int cnt = 0;
        while(t){
            t = t -> next;
            cnt++;
        }
        return cnt;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l2 ? l2 : l1;
        if(len(l1) < len(l2)) swap(l1, l2);
        int carry = 0;
        auto p1 = l1;
        ListNode* prev = NULL;
        while(l1 || l2){
            l1 -> val += (l2 ? (l2 -> val) : 0) + carry;
            carry = (l1 -> val) / 10;
            l1 -> val %= 10;
            
            prev = l1;
            l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        if(carry) prev -> next = new ListNode(carry);
        return p1;
    }
};