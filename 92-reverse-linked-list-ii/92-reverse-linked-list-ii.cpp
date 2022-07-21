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
    ListNode* reverse(ListNode *head){
        if(!head || !head -> next) return head;
        ListNode* prev = NULL;
        auto curr = head;
        auto nxt = head -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            if(nxt)
                nxt = nxt -> next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == NULL) return head;
        auto curr = head;
        ListNode* prev = NULL;
        int count = 1;
        while(count < left){
            count++;
            prev = curr;
            curr = curr -> next;
        }
        auto tail = curr;
        while(count < right){
            count++;
            curr = curr -> next;
        }
        auto en = curr -> next;
        curr -> next = NULL;
        if(prev)
            prev -> next = reverse(prev -> next);
        else
            head = reverse(head);
        tail -> next = en;
        return head;
        
    }
};