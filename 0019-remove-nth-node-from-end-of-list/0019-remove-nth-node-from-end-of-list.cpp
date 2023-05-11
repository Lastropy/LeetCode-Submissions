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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* prev = NULL;
        auto curr = head;
        auto nxt = head;
        for(int i = 0; i < n; i++)
            nxt = nxt -> next;
        if(!nxt) return head -> next;
        while(nxt){
            prev = curr;
            curr = curr -> next;
            nxt = nxt -> next;
        }
        prev -> next = curr -> next;
        delete curr;
        return head;
    }
};