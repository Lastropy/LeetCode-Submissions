class Solution {
public:
    bool winnerOfGame(string s) {
        if(s.size() < 3) return false;
        int n = s.size();
        int j = 0;
        vector<int> scores({0, 0});
        string curr = "";
        while(j < n){
            if(curr == "" || curr[0] == s[j]){
                curr += s[j];
                scores[s[j] - 'A'] += (curr.size() > 2);
            } else {
                curr = string(1, s[j]);
            }
            // cout << j << " -> "<< s[j] << " -> " << curr << " -> ";
            // for(int i: scores)
            //     cout << i << " ";
            // cout << endl;
            j++;
        }
        return scores[0] > scores[1];
    }
};