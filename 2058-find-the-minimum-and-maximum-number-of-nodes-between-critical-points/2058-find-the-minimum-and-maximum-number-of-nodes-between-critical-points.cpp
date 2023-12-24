class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head -> next || !head -> next -> next) return {-1, -1};
        auto prev = head;
        auto curr = head -> next;
        int focc = -1;
        int locc = -1;
        int idx = 1;
        vector<int> ans({INT_MAX, INT_MIN});
        while(curr -> next){
            if(((prev -> val) > (curr -> val) && (curr -> val) < (curr -> next -> val)) || ((prev -> val ) < (curr -> val) && (curr -> next -> val )< (curr -> val))){
                if(focc == -1) focc = idx;
                if(locc != -1){
                    ans[0] = min(ans[0], idx - locc);
                    ans[1] = idx - focc;
                }
                locc = idx;
            }
            idx++;
            prev = curr;
            curr = curr -> next;
        }
        return ans[0] == INT_MAX ? vector<int> ({-1, -1}): ans;
    }
};