class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {

        int ans = 1, curr = 0;
        int n = a.size();

        for(int i = 0, j = 0; j < n; j++){

            while(i < j && (curr & a[j]) != 0)
                curr = curr ^ a[i++];

            curr |= a[j];
            ans = max(ans, j - i + 1);

        }
        
        return ans;
    }
};