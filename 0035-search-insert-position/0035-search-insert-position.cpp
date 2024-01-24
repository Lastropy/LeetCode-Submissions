class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int n = a.size();
        
        int l = 0, h = n - 1;
        while(l <= h){
            int m = l + (h -l)/2;
            if(a[m] == t) return m;
            else if(a[m] < t) l = m + 1;
            else h = m - 1;
        }
        return l;
    }
};