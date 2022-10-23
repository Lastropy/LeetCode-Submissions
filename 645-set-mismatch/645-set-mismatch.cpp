class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int fn = -1, sn = -1;
        for(int i = 0; i < nums.size(); i++){
            int pos = abs(nums[i]) - 1;
            if(nums[pos] < 0){
                fn = abs(nums[i]);
                continue;
            }
            nums[pos] *= -1;
        }
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] > 0){
                sn  = i + 1;
            }
        }
        return {fn, sn};
    }
};