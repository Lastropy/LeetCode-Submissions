class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int curr_score = 0, max_score = 0;
        int s = 0, e = tokens.size() - 1;
        while( s <= e){
            if(tokens[s] <= power){
                power -= tokens[s++];
                curr_score++;
            }
            else if(curr_score >= 1){
                power += tokens[e--];
                curr_score--;
            }
            else{
                s++;
            }
            max_score = max(max_score, curr_score);
        }
        return max_score;
    }
};