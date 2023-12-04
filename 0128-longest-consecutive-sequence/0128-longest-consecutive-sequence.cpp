class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> present, checked;
        for(int i: nums)
            present[i] = 1;
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            if(!checked[curr]){
                if(!present[curr - 1]){
                    int nxt = curr + 1;
                    while(present[nxt])
                        checked[nxt++] = 1;
                    ans = max(ans, nxt - curr);
                }
                checked[curr] = 1;
            }
        }
        return ans;
    }
};