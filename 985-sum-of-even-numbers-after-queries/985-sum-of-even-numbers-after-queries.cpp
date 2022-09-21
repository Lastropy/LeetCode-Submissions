class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        vector<int> ans;
        for(int ele: nums)
            s += (ele % 2 == 0 ? ele : 0);
        
        for(auto q: queries){
            int val = q[0], idx = q[1];
            
            int oldV = nums[idx];
            nums[idx] += val;
            
            if(oldV % 2 == 0) s -= oldV;
            if(nums[idx] % 2 == 0) s += nums[idx]; 
            
            ans.push_back(s);
        }
        
        return ans;
        
    }
};