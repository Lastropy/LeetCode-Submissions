class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> prefs(nums.size());
        int n = nums.size();
        unordered_map< int, int> mp;
    
            
        
        prefs[0] = nums[0];
        mp[1] = -1;
        mp[2*prefs[0]] = 0;
        int ans = 0;
        for(int i = 1; i <n; i++)
        {
            prefs[i] = prefs[i-1] + nums[i];
            int val = 2 * prefs[i] - i; 
            if(mp.count(val))
                ans = max(ans, i - mp[val]);
            else
                mp[val] = i;
        }
        return ans;
    }
};