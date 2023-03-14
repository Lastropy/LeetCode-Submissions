class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        if(n < 2) return ans;
        for(int l = 0, r = n-1; l < r; ){
            if(nums[l] + nums[r] == k)
            {
                ans++; l++; r--;
            }
            else if(nums[l] + nums[r] < k)
                l++;
            else
                r--;
        }
        return ans;
    }
};