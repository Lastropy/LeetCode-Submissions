class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        int mini = p[0];
        for(int i = 1; i < p.size(); i++){
            ans = max(ans, p[i] - mini);
            mini = min(mini,  p[i]);
        }
        return ans;
    }
};