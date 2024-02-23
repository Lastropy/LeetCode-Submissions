class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        int s= 0, e = n - 1;
        while(s < e){
            int m = s + (e-s)/2;
            if((m == 0 || a[m] != a[m-1]) && (m == (n - 1) || a[m] != a[m + 1]))
                return a[m];
            if(((m % 2) && (a[m] == a[m-1])) || (!(m % 2) && (a[m] == a[m + 1]))) {
                s = m + 1; 
            } else {
                e = m - 1;   
            }
        }
        return a[e];
    }
};