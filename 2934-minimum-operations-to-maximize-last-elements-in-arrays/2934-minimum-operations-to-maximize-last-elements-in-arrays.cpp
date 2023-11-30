class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int mx = max(a[n-1], b[n-1]), mn = min(a[n-1], b[n-1]);
        int ans = 0, ans2 = 1;
        for(int i = 0; i < n - 1; i++){
            if(max(a[i], b[i])> mx || min(a[i], b[i]) > mn) return -1;
            if(a[i] > a[n-1] || b[i] > b[n-1]) ans++;
            if(a[i] > b[n-1] || b[i] > a[n-1]) ans2++;
        }
        return min(ans, ans2);        
    }
};