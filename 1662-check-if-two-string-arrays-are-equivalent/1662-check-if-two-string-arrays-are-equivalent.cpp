class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, p1 = 0 , w2 = 0,  p2 = 0;
        int n = word1.size();
        int m = word2.size();
        while(w1 < n && w2 < m){
            if(word1[w1][p1] == word2[w2][p2])
            {
                p1++;
                p2++;
            }
            else
                return false;
            if(p1 == word1[w1].size()){
                p1 = 0;
                w1++;
            }
            if(p2 == word2[w2].size()){
                p2 = 0;
                w2++;
            }
        }
        
        return w1 == n && w2 == m;
    }
};