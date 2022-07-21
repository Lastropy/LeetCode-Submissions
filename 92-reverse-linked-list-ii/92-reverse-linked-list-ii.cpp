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
    ListNode* getNode(ListNode* head, int c){
        if(c==1) return NULL;
        auto temp = head;
        for(int i = 1; i < c - 1; i++){
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == NULL) return head;
        auto curr = head;
        auto st = head;
        ListNode* prev = getNode(head, left);
        if(prev) st = prev -> next;
        else st = head;
        auto tail = getNode(head, right) -> next;
        auto en = tail -> next;
        tail -> next = NULL;
        if(prev)
            prev -> next = reverse(st);
        else
            head = reverse(st);
        st -> next = en;
        return head;
        
    }
};