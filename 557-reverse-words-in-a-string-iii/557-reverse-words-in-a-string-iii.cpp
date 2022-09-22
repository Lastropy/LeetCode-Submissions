class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i = 0, j = 0; j < n;){
            while(j < n && s[j] != ' ') j++;
            int t1 = i, t2 = j-1;
            while(t1 < t2)
                swap(s[t1++], s[t2--]);
            j++;
            i = j;
        }
        
        return s;
    }
};