class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int s = 0, e = a.size() - 1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(a[m] - (m + 1) < k) s = m + 1;
            else e = m - 1;
        }
        // int missing_num = a[e] + (k - (a[e] - (e + 1)));
        int missing_num = e + k + 1; 
        return missing_num;
    }
};