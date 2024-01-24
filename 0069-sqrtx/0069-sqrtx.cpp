class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        while(l <= h){
            long long m = l + (h - l) / 2;
            if(1LL * m * m == 1LL * x) return m;
            else if(m * m < x) l = m + 1;
            else h = m - 1;
        }
        return h;
    }
};