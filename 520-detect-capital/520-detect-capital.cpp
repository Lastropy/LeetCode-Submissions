class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() < 2) return true;
        if(islower(word[0]) && !islower(word[1])) return false;
        for(int i = 2;i < word.size(); i++)
            if(islower(word[i]) !=  islower(word[1]))
                return false;
        return true;
    }
};