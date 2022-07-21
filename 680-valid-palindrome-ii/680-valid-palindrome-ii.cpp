class Solution {
public:
    bool ifPalin(string s){
        // cout << s << endl;
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    bool validPalindrome(string s) {
        int i , j;
        int n = s.size();
        for(i = 0, j = n-1; i < j; i++, j--){
            if(s[i] != s[j])
            {
                return ifPalin(s.substr(0,i)+s.substr(i+1)) || ifPalin(s.substr(0,j) + s.substr(j+1));
            }
        }
        return true;
    }
};