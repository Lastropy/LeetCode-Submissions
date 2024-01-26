class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 1;
        int s = 1, e = n;
        while(s <= e){
            int m = s + (e - s )/2;
            long long coinsAtleast = ((1LL * m * (m + 1)) / 2);
            if(coinsAtleast > n) e = m - 1;
            else s = m + 1;
        }
        return e;
    }
};