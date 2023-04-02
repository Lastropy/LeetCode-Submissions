class Solution {
public:
    long long makeSubKSumEqual(vector<int>& a, int k) {
        long long n = a.size(), ans = 0;
        k = gcd(n,k);
        for(int i = 0; i < k; i++){
            vector<int> cycle;
            for(int j = i; a[j] != 0; j = (j + k) % n){
                cycle.push_back(a[j]);
                a[j] = 0;
            }
            
            nth_element(cycle.begin(), cycle.begin() + cycle.size() / 2, cycle.end());
            for(int ele: cycle)
                ans += abs(ele - cycle[cycle.size()/2]);
                
        }
        return ans;
    }
};