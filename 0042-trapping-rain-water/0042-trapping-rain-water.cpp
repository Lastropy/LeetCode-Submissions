class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        int l = 0, r = n-1, lmax = INT_MIN, rmax = INT_MIN;
        while(l <= r){
            if(h[l] <= h[r]){
                if(h[l] >= lmax) lmax = h[l];
                else ans += (lmax - h[l]);
                l++;
            }
            else {
                if(h[r] >= rmax) rmax = h[r];
                else ans += (rmax - h[r]);
                r--;
            }
        }
        return ans;
    }
};