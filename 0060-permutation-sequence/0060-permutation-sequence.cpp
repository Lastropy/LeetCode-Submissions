class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> a;
        for(int i = 1; i <= n; i++){
            a.push_back(i);
            fact *= i;
        }
        string ans = "";
        k = k - 1; // 0 - based indexing
        while(a.size() > 0){
            fact /= (a.size());
            int nextNumPos = k / fact;
            ans = ans + to_string(a[nextNumPos]);
            a.erase(a.begin() + nextNumPos);
            k = k % fact;
        }
        return ans;
    }
};