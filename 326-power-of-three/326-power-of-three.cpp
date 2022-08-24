class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        long l = 1;
        while(l < n)
            l *= 3;
        return l == n;
    }
};