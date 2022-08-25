class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for(char c: magazine)
            freq[c-'a']++;
        for(char c: ransomNote)
            freq[c-'a']--;
        for(int i: freq)
            if(i < 0)
                return false;
        return true;
        
    }
};