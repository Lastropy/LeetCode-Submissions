class Solution {
public:
     bool search(vector<int>& a, int t) {
        int n = a.size();
        int s = 0, e = n - 1;
        while(s <= e){
            int m = s + (e - s)/2;
            // if element found
            if(a[m] == t) return true;
            if(a[m] == a[s] && a[m] == a[e]){
                s++;
                e--;
                continue;
            }
            
            // left half is sorted
            if(a[s] <= a[m]){
                // element present in left half
                if(a[s] <= t && t <= a[m]){
                    e = m - 1;
                }
                // element not present in left half
                else s = m + 1;
            } 
            
            // right half is sorted
            else {
                // element present in right half
                if(a[m] <= t && t <= a[e]){
                    s = m + 1;
                }
                // element not present in right half
                else e = m - 1;
            }
        }
        // element not found
        return false;
    }
};