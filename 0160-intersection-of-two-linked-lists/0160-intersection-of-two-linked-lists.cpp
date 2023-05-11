/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* t){
        if(!t) return 0;
        return 1 + len(t -> next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // // Approach 1 -> brute force
        // // TC -> O(n * m)
        // // SC -> O (1)
        // auto temp2 = headB;
        // while(temp2){
        //     auto temp1 = headA;
        //     while(temp1){
        //         if(temp1 == temp2)
        //             return temp1;
        //         temp1 = temp1 -> next;
        //     }
        //     temp2 = temp2 -> next;
        // }
        // return NULL;
        
        // // Approach2 -> hash set
        // // TC -> O(n + m)
        // // SC -> O(n)
        // auto temp1 = headA;
        // unordered_set<ListNode *> s;
        // while(temp1){
        //     s.insert(temp1);
        //     temp1 = temp1 -> next;
        // }
        // auto temp2 = headB;
        // while(temp2){
        //     if(s.find(temp2) != s.end())
        //         return temp2;
        //     temp2 = temp2 -> next;
        // }
        // return NULL;
    
        int len1 = len(headA), len2 = len(headB);
        if(len1 < len2)
        {
            swap(headA, headB);
            swap(len1, len2);
        }
        int diff = len1 - len2;
        while(diff--){
            headA = headA -> next;            
        }
        while(headA && headB){
            if(headA == headB)
                return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
        
    }
};