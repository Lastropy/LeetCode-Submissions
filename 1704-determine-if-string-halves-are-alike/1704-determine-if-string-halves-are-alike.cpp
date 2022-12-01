class Solution {
public:
    bool halvesAreAlike(string s) {
        int count[2] = {0};
        int n =s.size();
        for(int i = 0; i < n; i++){
            char c = tolower(s[i]);
            if(c == 'a' || c=='e' || c == 'i' || c == 'o' || c== 'u')
                count[(2 * i)/n]++;
        }
        // cout << count[0] << " " <<count[1] << endl;
        return count[0] == count[1];
    }
};