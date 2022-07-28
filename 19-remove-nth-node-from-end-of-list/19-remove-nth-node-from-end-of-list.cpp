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
    int len(ListNode* head){
        if(!head) return 0;
        int cnt = 0;
        auto curr = head;
        while(curr){
            cnt++;
            curr = curr -> next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = len(head);
        int rem = length - n + 1;
        if(rem == 1)
        {
            auto temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        auto curr = head;
        ListNode* prev = NULL;
        for(int i = 1; i < rem; i++){
            prev = curr;
            curr = curr -> next;
        }
        auto temp = curr;
        if(curr) prev -> next = curr -> next;
        else prev -> next = NULL;
        delete temp;
        return head;
    }
};