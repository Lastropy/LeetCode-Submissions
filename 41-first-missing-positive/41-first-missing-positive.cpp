class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0 || nums[i] > n){
                nums[i] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            int ele = abs(nums[i]);
            if(ele > 0){
                if(nums[ele - 1] == 0)
                    nums[ele- 1] = ele;
                if(nums[ele-1] > 0)
                    nums[ele-1] *= -1;
            }
        }
        for(int i= 0; i < n; i++){
            if(nums[i] >= 0)
                return i+1;
        }
        return n+1;
    }
};