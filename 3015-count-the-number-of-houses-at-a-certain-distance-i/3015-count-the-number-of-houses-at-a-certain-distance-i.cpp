class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n, 0);
        if(x > y) return countOfPairs(n, y, x);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                int dist = min({abs(x - j) + abs(i - y) + 1, (i - j)});
                if(dist) ans[dist - 1]+= 2;
            }
        }
        return ans;
    }
};