class Solution {
public:
    double myPow(double x, long long n) {
        double ans = 1;
        if(n < 0) return (1.00 / myPow(x, -n));
        if(n == 0) return 1;
        while(n){
            if(n & 1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};