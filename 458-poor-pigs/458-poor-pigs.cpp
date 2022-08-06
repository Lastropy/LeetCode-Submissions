class Solution {
public:
    int poorPigs(int b, int mtd, int mtt) {
        int nots = (mtt / mtd) + 1;
        int ans = 0;
        int res = 1;
        while(res < b){
            res *= nots;
            ans++;
        }
        return ceil(log(b) / log(nots));
    }
};