class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0) return false;
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i =0, j = 0; j < n; j++){
            mp[nums[j]]++;
            if(mp[nums[j]] == 2)
                return true;
            if(j-i == k){
                mp[nums[i++]]--;
            }
        }
        return false;
    }
};