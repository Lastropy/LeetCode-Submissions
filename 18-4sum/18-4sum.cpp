class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int n = a.size();
        for(int i  = 0; i < n-3; i++ ){
            for(int j  = i+1; j < n-2; j++ ){
                int l = j+1;
                int r = n-1;
                long long tar = 1LL * target - 1LL * a[i] -1LL * a[j];
                while(l < r){
                    int sum = a[l] + a[r];
                    if(sum < tar)
                    {
                        while(l < r && a[l] == a[l+1])
                            l++;
                        l++;
                    }
                    else if(sum > tar){
                        while(r > l && a[r] == a[r-1])
                            r--;
                        r--;
                    }
                    else{
                        vector<int> temp({a[i],a[j],a[l],a[r]});
                        ans.push_back(temp);
                         while(l < r && a[l] == a[l+1])
                            l++;
                        l++;
                        while(r > l && a[r] == a[r-1])
                            r--;
                        r--;
                    }
                }
                while(j < n-2 && a[j] == a[j+1])
                    j++;
            }
             while(i < n-3 && a[i] == a[i+1])
                    i++;          
        }
        return ans;
    }
};