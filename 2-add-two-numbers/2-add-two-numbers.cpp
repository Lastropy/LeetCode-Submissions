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
        if(!l1) return l2;
        if(!l2) return l1;
        if(len(l1) < len(l2)) swap(l1, l2);
        int carry = 0;
        auto p1 = l1, p2  = l2;
        auto d = p1;
        ListNode* prev = NULL;
        while(p1 || p2){
            p1 -> val += (p2 ? (p2 -> val) : 0) + carry;
            carry = (p1 -> val) / 10;
            p1 -> val %= 10;
            
            prev = p1;
            p1 = p1 -> next;
            p2 = p2 ? p2 -> next: p2;
        }
        if(carry)
            prev -> next = new ListNode(carry);
        return l1;
    }
};