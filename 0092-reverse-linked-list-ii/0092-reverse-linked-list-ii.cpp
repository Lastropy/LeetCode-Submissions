class Solution {
private:
    ListNode* rev(ListNode*h){
        if(!h || !h -> next) return h;
        auto curr = h;
        ListNode *prev = NULL;
        auto nxt = curr -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            if(nxt) nxt = nxt -> next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head -> next || left == right) return head;
        
        auto first = head;
        ListNode* prev = NULL;
        for(int i = 1; i < left; i++)
        {
            prev = first;
            first = first -> next;
        }
        auto last = first;
        ListNode* nxt = NULL;
        for(int i = left-1; i < right - 1; i++){
            last = last -> next;
            nxt = last -> next;
        }
        if(nxt){
            last -> next = NULL;
        }
        last = rev(first);
        if(prev){
            prev -> next = last;
        } else {
            head = last;
        }
        first -> next = nxt;
        return head;        
    }
};