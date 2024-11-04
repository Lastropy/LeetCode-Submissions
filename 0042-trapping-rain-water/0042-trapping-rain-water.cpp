class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        int l = 0, r = n-1, lmax = INT_MIN, rmax = INT_MIN;
        while(l <= r){
            if(rmax <= lmax){
                if(rmax < h[r]) rmax = h[r];
                ans += rmax - h[r];
                r--;
            } else {
                if(lmax < h[l]) lmax = h[l];
                ans += lmax - h[l];
                l++;
            }
        }
        return ans;
    }
};