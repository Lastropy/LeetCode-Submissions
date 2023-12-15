class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if(k <= 0) return 0;
        int ans = 0, n= a.size(), curr_prod = 1;
        for(int i= 0, j = 0; j < n; j++){
            curr_prod *= a[j];
            while(curr_prod >= k && i <= j){
                curr_prod /= a[i++];
            }
            ans += (j - i + 1);
        }
        return ans;
    }
};