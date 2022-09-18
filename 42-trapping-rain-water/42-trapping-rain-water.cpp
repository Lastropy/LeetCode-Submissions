class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int lmax = INT_MIN, rmax = INT_MIN;
        int l = 0, r = n - 1;
        int ans = 0;

        while(l <= r){
            if(lmax <= rmax){
                if(h[l] > lmax)
                    lmax = h[l];
                else
                    ans += (lmax - h[l]);
                l++;
            }
            else{
                if(h[r] > rmax)
                    rmax = h[r];
                else
                    ans += (rmax - h[r]);
                r--;
            }
        }
        return ans;
    }
};