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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto p1 = list1;
        auto p2 = list2;
        auto dummy  = new ListNode(0);
        auto d = dummy;
        while(p1 && p2){
            if(p1 -> val < p2 -> val){
                dummy -> next = p1;
                p1 = p1 -> next;
            }
            else{
                dummy -> next = p2;
                p2 = p2 -> next;
            }
            dummy = dummy -> next;
        }
        if(p1) dummy -> next = p1;
        if(p2) dummy -> next = p2;
        return d-> next;
    }
};