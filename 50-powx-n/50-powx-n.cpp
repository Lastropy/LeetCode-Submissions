class Solution {
public:
    double p(double x ,  long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        
        double mult = x;
        double ans = 1;
        while(n){
            if(n & 1){
               ans *= mult; 
            }
            n >>= 1;
            mult *= mult;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(x == 0) return x;
        if(x == 1) return x;
        if(n < 0) return (1 / p(x,-1 * (1LL * n)));
        return p(x, n);
    }
};