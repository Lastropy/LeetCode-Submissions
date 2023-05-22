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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) return head;
        
        auto curr = head;
        ListNode* prev = NULL;
        while(curr && curr -> next){
            if(curr -> val == curr -> next -> val){
                int v = curr -> val;
                while(curr && curr -> val == v){
                    if(prev){
                        auto temp = curr;
                        prev -> next = curr -> next;
                        delete temp;
                        curr = prev -> next;
                    }else{
                        auto temp = head;
                        head = head -> next;
                        delete temp;
                        curr = head;
                    }
                }
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
    
};