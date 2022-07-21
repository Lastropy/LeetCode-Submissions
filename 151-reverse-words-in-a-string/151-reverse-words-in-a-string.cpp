class Solution {
public:
    void rev(int st, int en, string &s){
        if(st >= en) return;
        while(st < en){
            swap(s[st++], s[en--]);
        }
    }
    int skipSpace(string &a){
        int i = 0, j = 0;
        int n = a.size();
        while(j < n){
            while(j < n && a[j] == ' ') j++;
            while(j < n && a[j] != ' ') a[i++] = a[j++];
            while(j < n && a[j] == ' ') j++;
            if(j < n) a[i++] = ' ';
        }
        return i;
    }
    string reverseWords(string s) {
        int n = s.size();
        for(int i = 0, j = 0; j <= n; j++){
            if( i  < n && s[i] == ' ')
            {
                i++;
                continue;
            }
            if(j < n && s[j] != ' ')
                continue;
            rev(i, j-1, s);
            i = j+1;
            j++;
        }
        rev(0, n-1, s);
        int pos = skipSpace(s);
        return s.substr(0,pos);
    }
};