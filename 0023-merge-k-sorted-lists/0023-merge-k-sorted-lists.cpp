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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i] -> val, lists[i]});
            }
        }
        
        auto ans = new ListNode(-1);
        auto ans2 = ans;
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            auto nxt = (tp.second) -> next;
            ans -> next = tp.second;
            if(nxt) pq.push({nxt -> val, nxt});
            ans = ans -> next;
        }
        return ans2 -> next;
    }
};