class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        auto ans2 = ans;
        auto curr = head;
        int sum = 0;
        while(curr){
            if(curr -> val == 0 && curr != head){
                ans -> next = new ListNode(sum);
                ans = ans -> next;
                sum = 0;
            }
            else {
                sum += curr -> val;
            }
            curr = curr -> next;
        }
        return ans2 -> next;
    }
};