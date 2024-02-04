class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size(), s = 0, e = n - 1;
        while(s < e){
            int m = s + (e - s)/2;
            if(a[m] > a[e]) s = m + 1;
            else if(a[m] < a[e]) e = m;
            else e--;
        }
        return a[s % n];
    }
};