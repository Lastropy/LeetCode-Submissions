class Solution {
public:
    bool checkPowersOfThree(int n) {
        int dig = (log(n)/ log(3))+1;
        int p = pow(3,dig-1);
        while(dig != -1){
            if(p <= n)
                n -= p;
            p/=3;
            dig--;
        }
        if(n == 0) return true;
        return false;
    }
};