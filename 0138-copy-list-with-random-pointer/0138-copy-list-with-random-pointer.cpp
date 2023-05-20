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
        auto ans = new Node(0);
        auto curr = ans;
        auto curr2 = head;
        while(curr2){
            curr -> next = new Node(curr2 -> val);
            curr = curr -> next;
            curr -> random = curr2;
            auto temp = curr2 -> next;
            curr2 -> next = curr;
            curr2 = temp;
        }
        unordered_map<Node *, Node *> mp;
        curr = ans -> next;
        while(curr){
            mp[curr -> random] = curr -> next ? curr -> next -> random: NULL;
            if(curr -> random -> random)
                curr -> random = curr -> random -> random -> next;
            else
                curr -> random = NULL;
            curr = curr -> next;
        }
        
        for(auto [k, v]: mp)
            k -> next = v;
        return ans -> next;
    }
};