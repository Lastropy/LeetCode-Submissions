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
        if(!head || !(head -> next)) 
            return head;
        ListNode *prev = NULL;
        auto curr = head;
        auto nxt = head -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            if(nxt) nxt = nxt -> next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !(head -> next)) 
            return true;

        auto slow = head, fast = head;
        ListNode* prev = NULL;
        while(fast && fast -> next){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = head;
        slow = reverse(slow);
        while(slow){
            if(fast -> val != slow -> val)
                return false;
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
        
        
    }
};