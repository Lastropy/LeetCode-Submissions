class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int pmax[nums.size()];
        int smin[nums.size()];
        pmax[0] = nums[0];
        smin[nums.size()-1] = nums.back();
        for(int i = 1; i < nums.size(); i++){
            pmax[i] = max(pmax[i-1], nums[i]);
            smin[nums.size()-i-1] = min(smin[nums.size()-i],nums[nums.size()-i-1]);
        }
        int ans = -1;
        for(int i = 0; i < nums.size()-1 ; i++){
            if(smin[i+1] >= pmax[i])
                return i+1;
        }
        return ans;
    }
};