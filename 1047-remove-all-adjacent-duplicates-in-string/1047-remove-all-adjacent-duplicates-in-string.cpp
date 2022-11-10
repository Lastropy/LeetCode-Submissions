class Solution {
public:
    string removeDuplicates(string s) {
        int sp = 0;
        for(int i = 0; i < s.size(); i++){
            if(sp > 0 && s[sp - 1] == s[i]) sp--;
            else s[sp++] = s[i];
        }
        return s.substr(0, sp);
    }
};