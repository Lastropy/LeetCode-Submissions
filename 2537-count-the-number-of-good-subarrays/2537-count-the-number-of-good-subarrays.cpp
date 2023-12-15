class Solution {
public:
    long long countGood(vector<int>& a, int k) {
        unordered_map<int, int> mp;
        int n = a.size();
        int curr_pairs = 0;
        long long ans = 0;
        for(int i = 0, j = 0; j < n; j++){
            curr_pairs += mp[a[j]];
            mp[a[j]]++;
            while(curr_pairs >= k){
                ans+=(n-j);
                mp[a[i]]--;
                curr_pairs -= mp[a[i]];
                i++;
            }
            // cout << curr_pairs << '\n';
        }
        return ans;
    }
};