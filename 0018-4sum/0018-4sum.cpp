class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                long long tar = 1ll * t - 1LL * a[j] - 1LL * a[i];
                for(int k = j + 1, l = n - 1; k < l;){
                    long long curr = a[k] * 1LL + a[l] * 1LL;
                    if(curr == tar) {
                        ans.push_back({a[i], a[j], a[k], a[l]});
                        while(l > k && a[l] == a[l - 1]) l--;
                        l--;
                        while(k < l && a[k] == a[k + 1]) k++;
                        k++;
                    }
                    else if(curr < tar){
                        while(k < l && a[k] == a[k+1]) k++;
                        k++;
                    } 
                    else {
                        while(l > k && a[l] == a[l-1]) l--;
                        l--;
                    }
                }
                while(j < n - 2 && a[j] == a[j+1]) j++;
            }
            while(i < n - 3 && a[i] == a[i+1]) i++;
        }
        return ans;
    }
};