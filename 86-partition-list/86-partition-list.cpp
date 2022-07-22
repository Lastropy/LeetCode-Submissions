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
        ListNode* big = new ListNode();
        auto d1 = smol,d2 = big, curr = head;
        while(curr){
            auto node = new ListNode(curr -> val);
            if(curr -> val < x)
            {
                smol -> next = node;
                smol = smol -> next;
            }
            else{
                big -> next = node;
                big = big -> next;
            }
            curr = curr -> next;
        }
        d1 = d1 -> next;
        d2 = d2 -> next;
        if(d1){
            smol -> next = d2;
            return d1;
        }
        return d2;
    }
};