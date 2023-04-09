class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        unordered_map<int, vector<int>> mp;
        int n = a.size();
        vector<long long> ans(n, 0);
        
        for(int i = 0; i < n; i++)
            mp[a[i]].push_back(i);
        
        for(auto [k,v] : mp){
            long long left_sum = 0, right_sum = 0, pref_sum_left = 0, pref_sum_right = 0;
            
            for(int j = v.size() - 1; j >= 0; j--)
                pref_sum_right += v[j];
            
            for(int j = 0; j < v.size(); j++){
                pref_sum_right -= v[j];
                right_sum = (pref_sum_right - 1LL* v[j] * (v.size() - 1 - j));
                left_sum = (1LL * j * v[j] - pref_sum_left);
                pref_sum_left += v[j];
                ans[v[j]] = left_sum + right_sum;
            }
        }
        
        return ans;
    }
};