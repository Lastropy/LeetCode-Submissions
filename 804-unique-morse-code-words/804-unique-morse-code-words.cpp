class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});

        set<string> ans;

        for(string s: words){

            string res = "";

            for(char c: s)
                res += morse[c-'a'];

            ans.insert(res);
        }

        return ans.size();
    }
};