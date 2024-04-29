class Solution {
public:
    bool solve(vector<int>& a, vector<bool>& taken, int subsetSum, int &tar, int k, int idx){
        if(k == 0) return true;
        if(subsetSum == tar) return solve(a, taken, 0, tar, k - 1, 0);
        
        for(int i = idx; i < a.size() && (subsetSum + a[i]) <= tar; i++){
            if(i > 0 && !taken[i - 1] && a[i] == a[i-1]) continue;
            if(!taken[i]){
                taken[i] = 1;
                if(solve(a, taken, subsetSum + a[i], tar, k, i + 1)) return true;
                taken[i] = 0;
            }
        }
        return false;        
    }
    
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = a.size();
        int sum = (accumulate(a.begin(), a.end(), 0));
        
        if(k <= 1) return true;
        if(n < k || (sum % k != 0)) return false;
        
        sort(a.begin(), a.end());
        vector<bool> taken(n, 0);
        int tar = sum / k;
        
        return solve(a, taken, 0, tar, k, 0);
    }
};