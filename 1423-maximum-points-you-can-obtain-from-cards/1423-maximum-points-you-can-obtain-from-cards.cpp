class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n  = cardPoints.size();
        int ans = 0;
        for(int i  = 0 ; i < min(k, n); i++)
            ans += cardPoints[i];
        if(k >= n)
            return ans;
        int a = ans;
        int i =  k - 1;
        int j  = n -1;
        while(i >= 0){
            ans -= cardPoints[i--];
            ans += cardPoints[j--];
            a = max(ans, a); 
        }
        return a;
    }
};