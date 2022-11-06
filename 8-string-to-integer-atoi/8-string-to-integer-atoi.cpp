class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long ans = 0;
        int neg = 1, i = 0;
        bool seen = false;
        long nclamp = INT_MIN, pclamp = INT_MAX;

        while(i < n && s[i] == ' ') i++;
        if(i < n && (s[i] == '+' || s[i] == '-')) 
            neg *= (s[i++] == '+' ? 1: -1);

        for( ; i < n; i++){
            if(isdigit(s[i])){
                ans = ans * 10 + (s[i] - '0');
                seen =  true;
            }
            else
                break;
            
            if(neg == -1 && ans * neg < nclamp)
                return nclamp;
            if(neg == 1 && ans > pclamp)
                return pclamp;
        }
        return ans * neg;
    }
};