class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size(), s = 0, e = n - 1;
        while(s <= e){
            int m = s + (e - s)/2;
            if((m && (a[m - 1] < a[m])) || (m < n - 1 && (a[m+1] > a[m]))) s = m + 1;
            else e = m - 1;
        }
        return e;
    }
};