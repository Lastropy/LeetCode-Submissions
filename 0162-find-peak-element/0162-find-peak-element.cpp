class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size(), s = 0, e = n - 1;
        while(s<=e){
            int m = s + (e - s) /2;
            if((m == 0 || a[m-1] < a[m]) && (m == n - 1 || a[m+1] < a[m]))
                return m;
            else if((m && (a[m-1] > a[m])) || (m < n - 1 && (a[m + 1] < a[m])))
                e = m - 1;
            else s = m + 1;
        }
        return -1;
    }
};