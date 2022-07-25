class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n =  nums.size();
        int ans  = 0;
        int curr1 = 0, curr2 = 0;
        for(int j = 0; j < n; j++){
            curr1 += nums[j];
            curr2 += nums[j];
            ans = max({ans, curr1, abs(curr2)});
            if(curr1 < 0)
                curr1  = 0;
            if(curr2 > 0)
                curr2 = 0;
        }
        return  ans;
    }
};