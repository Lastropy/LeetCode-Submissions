class Solution {
public:
    int first_occ(vector<int> &a, int t){
        int s = 0, e = a.size() - 1;
        while(s <= e){
            int m = s + (e - s)/2;
            if(a[m] >= t){
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return (s==a.size() || a[s] != t) ? -1: s;
    }
    
    int last_occ(vector<int>&a, int t, int s){
        int e = a.size() - 1;
         while(s <= e){
            int m = s + (e - s)/2;
            if(a[m] <= t){
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return e;
    }
    vector<int> searchRange(vector<int>& a, int t) {
        int foc = first_occ(a, t);
        if(foc == -1) return {-1, -1};
        int loc = last_occ(a, t, foc);
        return {foc, loc};
    }
};