class Solution {
public:
    bool canShip(vector<int>& a, int mid, int t){
        int ans =0, curr = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] > mid) return false;
            if(curr + a[i] <= mid){
                curr += a[i];
            } else {
                ans++;
                curr = a[i];
            }
        }
        return ((ans + 1) <= t);
    }
    
    int shipWithinDays(vector<int>& w, int t) {
        int s = 1;
        int e = accumulate(w.begin(), w.end(), 0);
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(canShip(w, mid, t)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};