class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        for(int i = 0, j = 0; j < n; j++){
            i = j;
            while(j < n && s[j] != ' ') j++;
            int t1 = i, t2 = j-1;
            for(int t1 = i, t2 = j-1 ; t1 < t2; t1++, t2--)
                swap(s[t1], s[t2]);
        }
        
        return s;
    }
};