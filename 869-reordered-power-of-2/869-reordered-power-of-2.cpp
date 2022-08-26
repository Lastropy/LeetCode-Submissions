class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        
        vector<int> target(10, 0), f(10,0);

        string num = to_string(n);

        for(char c: num)
            f[c-'0']++;

        int len = num.size();
        int curr= 1;

        string s = to_string(curr);        

        while(len >= s.size() && curr <= 1e9){
            if(len == s.size()){
                vector<int> cpy(f.begin(), f.end());

                for(char c: s)
                    cpy[c-'0']--;

                if(cpy == target)
                    return true; 
            }
            curr *= 2;
            s = to_string(curr);
        }
        
        return false;
    }
};