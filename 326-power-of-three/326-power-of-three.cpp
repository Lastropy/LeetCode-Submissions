class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        // long l = 1;
        // while(l < n)
        //     l *= 3;
        // return l == n;
        
        double div = log10(n) / log10(3);
        return (fmod(div, 1)) == 0;
        
    }
};