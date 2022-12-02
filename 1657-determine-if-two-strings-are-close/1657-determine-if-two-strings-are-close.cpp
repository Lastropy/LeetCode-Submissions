class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        
        vector<int> mp1(26, 0), mp2(26, 0);
        for(char c: word1)
            mp1[c - 'a']++;
        for(char c: word2)
            mp2[c  - 'a']++;
        
        vector<int> prob1, prob2;
        for(int i =0; i < 26; i++){
            if(!mp1[i] && !mp2[i]) 
                continue;
            else if(!mp1[i] && mp2[i])
                return false;
            else if(mp1[i] && !mp2[i])
                return false;
            else if(mp1[i] != mp2[i])
                prob1.push_back(mp1[i]), prob2.push_back(mp2[i]);
        }
        sort(begin(prob1), end(prob1));
        sort(begin(prob2), end(prob2));
        
        
        
        
        return prob1 == prob2;
    }
};