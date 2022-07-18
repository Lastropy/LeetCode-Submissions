class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int maxP = 0;
        for(int i = 1; i < prices.size(); i++){
            lowest = min(prices[i],lowest);
            maxP = max(maxP, prices[i]-lowest);
        }
        return maxP;
    }
};