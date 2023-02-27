class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans =0;
        for(int i: nums){
            ans += mp[i+k];
            ans += mp[i-k];
            mp[i]++;
        }
        return ans;
    }
};