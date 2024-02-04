class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int s = 0, e  = n - 1;
        while(s < e){
            int m = s + (e - s) /2 ;
            if(a[m] < a[e]) e = m;
            else s = m + 1;
        }
        return a[s % n];
    }
};