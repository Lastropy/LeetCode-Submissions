class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> prefs(nums.size());
        int n = nums.size();
        
        prefs[0] = nums[0];
        for(int i = 1; i  < n; i++)
            prefs[i] = prefs[i-1] + nums[i];
        
        unordered_map< int, int> mp;
        mp[1] = -1;
        int ans = 0;
        for(int i = 0; i <n; i++)
        {
            int val = 2 * prefs[i] - i; 
            if(mp.count(val))
                ans = max(ans, i - mp[val]);
            else
                mp[val] = i;
        }
        return ans;
    }
};