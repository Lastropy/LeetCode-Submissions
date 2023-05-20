/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        auto curr = head;
        
        // STEP - 1
        while(curr){
            auto nxt = curr -> next;
            curr -> next = new Node(curr -> val);
            curr -> next -> next = nxt;
            curr = nxt;
        }
        
        // STEP - 2
        curr = head;
        while(curr){
            curr -> next -> random = curr -> random ? curr -> random -> next : NULL;
            curr = curr -> next -> next;
        }
        
        // STEP - 3
        curr = head;
        auto ans = curr -> next;
        while(curr){
            auto nxt = curr -> next;
            curr -> next = curr -> next -> next;
            nxt -> next = nxt -> next ? nxt -> next -> next : NULL;
            nxt = nxt -> next;
            curr = curr -> next;
        }
        
        return ans;
        
        
        
    }
};