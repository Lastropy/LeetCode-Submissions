class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        
        vector<int> mp1(26, 0), mp2(26, 0);
        set<char> s1, s2;
        for(char c: word1){
            mp1[c - 'a']++;
            s1.insert(c);
        }
        for(char c: word2){
            mp2[c  - 'a']++;
            s2.insert(c);
        }
        sort(begin(mp1), end(mp1));
        sort(begin(mp2), end(mp2));
        
        
        
        
        return ((mp1 == mp2 )&& (s1 == s2));
    }
};