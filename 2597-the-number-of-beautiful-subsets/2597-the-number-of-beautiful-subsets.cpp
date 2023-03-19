class Solution {
private:
    int n,ans =0;
    unordered_map<int, int> curr;
    void dfs(vector<int> &a, int k , int idx){
        if(idx == n){
            ans++;
            return;
        } 
        
        if(!curr[a[idx] - k]){
            curr[a[idx]]++;
            dfs(a, k, idx+1);
            curr[a[idx]]--;
        }
        dfs(a, k, idx+1);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, k , 0);
        return ans - 1;
    }
};