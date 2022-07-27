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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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
        auto temp1 = headA;
        unordered_set<ListNode *> s;
        while(temp1){
            s.insert(temp1);
            temp1 = temp1 -> next;
        }
        auto temp2 = headB;
        while(temp2){
            if(s.find(temp2) != s.end())
                return temp2;
            temp2 = temp2 -> next;
        }
        return NULL;
    }
};