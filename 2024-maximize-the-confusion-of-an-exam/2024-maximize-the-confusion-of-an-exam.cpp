class Solution {
public:
    int win(string s , int k ,char c){
        int n  = s.size();
        int i = 0, j = 0;
        int ans = 0;
        int count = 0;
        for(i = 0, j = 0; j < n; j++){
            if(s[j] != c)
                count++;
            while(i < n && count > k){
                if(s[i] != c)
                    count--;
                i++;
            }
            if(count <= k )
                ans = max(ans, j - i + 1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(win(s,k,'T'), win(s,k,'F'));
    }
};