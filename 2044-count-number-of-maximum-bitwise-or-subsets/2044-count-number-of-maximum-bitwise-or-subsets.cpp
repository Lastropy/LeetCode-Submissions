class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 1<< nums.size();
        int mor = 0;
        int count = 0;
        for(int i: nums)
            mor |=  i;
       for(int i = 1; i < l; i++ ){
           int curr = 0;
           for(int j = 0; j < nums.size(); j++){
               if(i & (1 << j)){
                   curr |= nums[j];
               }
           }
           if(curr == mor){
               count++;
           }
       }
        return count;
    }
};