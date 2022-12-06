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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head-> next) return head;
        ListNode* o = new ListNode();
        auto ans = o;
        ListNode* e = new ListNode();
        auto ans2 = e;
        
        int count = 1;
        while(head){
            auto temp = new ListNode(head->val);
            if(count % 2) {
                o -> next = temp;
                o = o -> next;
            }
            else{
                e -> next = temp;
                e = e -> next;
            }
            count++;
            head = head -> next;
        }
        
        o -> next = ans2 -> next;
        return ans -> next;
        
    }
};