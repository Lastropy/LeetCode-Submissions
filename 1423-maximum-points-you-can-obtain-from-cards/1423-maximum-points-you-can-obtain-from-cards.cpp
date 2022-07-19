class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n  = cardPoints.size();
        int a = 0;
        for(int i  = 0 ; i < min(k, n); i++)
            a += cardPoints[i];
        if(k < n){
            for(int i = k - 1, j = n - 1, ans = a; i >= 0 ; i--, j--){
                ans = ans - cardPoints[i] + cardPoints[j];
                a = max(ans, a); 
            }
        }
        return a;
    }
};