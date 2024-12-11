class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        if(n == 1 || a[0] < a[n - 1]) return a[0];
        int l = 0, h = n - 1, mid = 0;
        while(l <= h) {
            mid = l + (h - l)/2;
            cout << mid << endl;
            if(((mid == 0) || (a[mid] > a[mid - 1])) && ((mid == n - 1) || (a[mid] > a[mid + 1]))){
                break;
            } else if(a[0] <= a[mid]){
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return a[mid + 1];
    }
};