class Solution {
private: 
    ListNode* rev(ListNode * h){
        if(!h || !h -> next) return h;
        auto curr = h;
        auto nxt = h -> next;
        ListNode* prev = NULL;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            if(nxt) nxt = nxt -> next;
        }
        return prev;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next) return head;
        
        auto first = head;
        ListNode* prev = NULL;
        
        while(first){
            auto last = first -> next;
            ListNode* nxt = NULL;
            if(last) {
                nxt = last -> next;
                last -> next = NULL;
            }
            last = rev(first);
            if(prev){
                prev -> next = last;
            }
            else {
                head = last;
            }
            first -> next = nxt;
            prev = first;
            first = nxt;
        }
        return head;
    }
};