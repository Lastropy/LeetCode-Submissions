class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> present, checked;
        
        int ans = 0;
        for(int i: nums)
            present[i] = 1;
        for(int i : nums){
            if(!checked[i]){
                if(!present[i-1]){
                    int curr = i+1;
                    while(present[curr])
                        curr++;
                    ans = max(ans, curr-i);
                }
                checked[i] = 1;
            }
        }
        return ans;
    }
};