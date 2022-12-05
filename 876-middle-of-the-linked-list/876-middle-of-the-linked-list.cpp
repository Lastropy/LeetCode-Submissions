class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head) return NULL;
        if(!(head -> next)) return head;
        auto slow = head, fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};