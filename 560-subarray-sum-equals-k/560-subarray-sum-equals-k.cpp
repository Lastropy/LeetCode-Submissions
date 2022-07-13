class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        // if(k == 0) 
        //     mp[0] = 1;
        int count = 0;
        int sum = 0;
        for(int i  = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k)
                count++;
            int tar = sum - k;
            count += mp[tar];
            mp[sum]++;
        }
        return count;
    }
};