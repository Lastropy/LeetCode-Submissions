class Solution {
    public:
using ll = long long;
int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
    long long n = r1.size(), ans = 0;
    vector<pair<int,int>> diff;
    for(int i = 0; i < n; i++)
        diff.push_back({r1[i] - r2[i], i});

    sort(diff.begin(), diff.end(), [&](const auto &a, const auto &b){
        return a.first > b.first;
    });
    for(int i = 0; i < k; i++){
        ans += r1[diff[i].second];
        r2[diff[i].second] = 0;
    }
    return accumulate(r2.begin(), r2.end(), ans);
}
};