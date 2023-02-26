class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefs = nums[0];
        int n = nums.size();
        unordered_map< int, int> mp;
        mp[1] = -1, mp[2*prefs] = 0;
        int ans = 0;
        for(int i = 1; i <n; i++)
        {
            prefs +=  nums[i];
            int val = 2 * prefs - i; 
            if(mp.count(val))
                ans = max(ans, i - mp[val]);
            else
                mp[val] = i;
        }
        return ans;
    }
};