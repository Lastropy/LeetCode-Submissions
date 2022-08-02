class Solution {
public:
    int check(vector<vector<int>> &a, int m){
        int res = 0;
        int n = a.size();
        for(int i = 0; i < n; i++){
            int l = 0;
            int h = n - 1;
            int curr = -1;
            while(l <= h){
                int mid = l + (h - l) / 2;
                if(a[i][mid] <= m){
                    curr = mid;
                    l = mid + 1;
                }
                else
                    h = mid - 1;
            }
            res += (curr+1);
        }
        return res;
    }
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        int mn = a[0][0], mx = a[n-1][n-1];
        int ans = -1;
        while(mn <= mx){
            int mid = mn + (mx - mn) / 2;
            int res = check(a, mid);
            if(res >= k){
                ans = mid;
                mx = mid - 1;
            }
            else
                mn = mid + 1;
        }
        return ans;
    }
};