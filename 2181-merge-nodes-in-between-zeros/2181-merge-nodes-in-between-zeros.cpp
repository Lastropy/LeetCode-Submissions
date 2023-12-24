class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        auto curr = head;
        auto curr2 = head;
        ListNode* prev = NULL;
        int sum = 0;
        while(curr){
            if(curr -> val == 0 && curr != head){
                curr2 -> val = sum;
                prev = curr2;
                curr2 = curr2 -> next;
                sum = 0;
            }
            else {
                sum += curr -> val;
            }
            curr = curr -> next;
        }
        prev -> next = NULL;        
        while(curr2){
            auto temp = curr2;
            curr2 = curr2 -> next;
            delete temp;
        }
        return head;
    }
};