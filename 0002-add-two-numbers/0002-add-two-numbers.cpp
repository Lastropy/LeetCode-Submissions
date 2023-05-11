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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1? l1: l2;
        
        int carry =0;
        auto ans = new ListNode();
        auto ans2 = ans;
        while(l1 && l2){
            l1 -> val += l2 -> val + carry;
            carry = (l1 -> val) / 10;
            l1 -> val %= 10;
            ans -> next = l1;
            ans = ans -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        if(l1){
            ans -> next = l1;
            while(carry && l1){
                l1 -> val += carry;
                carry = (l1 -> val) / 10;
                l1 -> val %= 10;
                ans -> next = l1;
                ans = ans -> next;
                l1 = l1 -> next;
            }
        }
        
         if(l2){
             ans -> next = l2;
            while(carry && l2){
                l2 -> val += carry;
                carry = (l2 -> val) / 10;
                l2 -> val %= 10;
                ans -> next = l2;
                ans = ans -> next;
                l2 = l2-> next;

            }
        }
        if(carry){
            ans -> next = new ListNode(carry);
        }
        return ans2 -> next;
    }
};