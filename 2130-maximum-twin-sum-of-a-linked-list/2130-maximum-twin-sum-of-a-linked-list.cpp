class Solution {
private: 
    ListNode* rev(ListNode *h){
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
    int pairSum(ListNode* head) {
        auto fast = head;
        auto slow = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow = rev(slow);
        fast = head;
        int ans = INT_MIN;
        while(slow){
            ans = max((slow -> val) + (fast -> val), ans);
            fast = fast -> next;
            slow = slow -> next;
        }
        return ans;
    }
};