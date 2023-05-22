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
                    auto temp = curr;
                    if(prev){
                        prev -> next = curr -> next;
                        curr = prev -> next;
                    } 
                    else
                    {
                        head = curr -> next;
                        curr = head;
                    }
                    delete temp;
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