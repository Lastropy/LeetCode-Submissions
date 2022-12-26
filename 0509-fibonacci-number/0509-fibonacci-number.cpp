class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int f = 0, s = 1, t;
        n--;
        while(n--){
            t = f + s;
            f = s;
            s = t;
        }
        return t;
    }
};