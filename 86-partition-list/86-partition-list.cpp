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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smol = new ListNode();
        auto d1 = smol;
        ListNode* big = new ListNode();
        auto d2 = big;
        auto curr = head;
        while(curr){
            if(curr -> val < x)
            {
                smol -> next = new ListNode(curr -> val);
                smol = smol -> next;
            }
            else{
                big -> next = new ListNode(curr -> val);
                big = big -> next;
            }
            curr = curr -> next;
        }
        d1 = d1 -> next;
        d2 = d2 -> next;
        auto ans = new ListNode();
        auto d3 = ans;
        if(d1){
            ans -> next = d1;
        }
        while(ans -> next)
            ans = ans -> next;
        if(d2){
            ans -> next = d2;
        }
        return d3 -> next;
       
    }
};