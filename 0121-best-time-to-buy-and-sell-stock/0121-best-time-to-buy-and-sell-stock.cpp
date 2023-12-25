class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mn = a[0];
        int ans = 0;
        for(int i = 1; i < a.size(); i++){
            ans = max(ans, a[i] - mn);
            mn = min(mn, a[i]);
        }
        return ans;
    }
};