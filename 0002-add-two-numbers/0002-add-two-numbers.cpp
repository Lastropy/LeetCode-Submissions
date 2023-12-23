class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto a = l1;
        auto b = l2;
        int carry = 0;
        ListNode* ans = new ListNode(-1);
        auto ans2 = ans;
        while(l1 || l2){
            ans -> next = new ListNode(carry);
            if(l1){
                ans -> next -> val += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                ans -> next -> val += l2 -> val;
                l2 = l2 -> next;
            }
            carry = (ans -> next -> val) / 10;
            ans -> next -> val = (ans -> next -> val) % 10;
            ans = ans -> next;
        }
        
        
        while(carry){
            ans -> next = new ListNode(carry);
            carry = (ans -> next -> val) / 10;
            ans -> next -> val = (ans -> next -> val) % 10;
        }
        return ans2 -> next;
    }
};