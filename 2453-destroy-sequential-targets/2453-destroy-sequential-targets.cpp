class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int, int> mp;
        int high = INT_MIN;
        for(int i : nums){
            int rem = i % space;
            mp[rem]++;
            high = max(high, mp[rem]); 
        }
        int ans = INT_MAX;
        for(int i: nums){
            if(mp[i % space] == high)
                ans = min(ans, i);
        }
        return ans;
    }
};