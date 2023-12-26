class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        // we want to do binary search on smaller array
        if(n1 > n2) return findMedianSortedArrays(b, a);
        // n1 is guaranteed to be smaller now.
        // Start binary search
        int low = 0, high = n1;
        while(low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = ((n1 + n2 + 1) /2) - mid1;
            // Incase l1 or l2 does not exist
            int l1 = INT_MIN, l2 = INT_MIN;
            // Incasse r1 or r2 does not exist
            int r1 = INT_MAX, r2 = INT_MAX;
            // Check if valid indexes and assign
            if(mid1 < n1) r1 = a[mid1];            
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];      
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
            
            // Check for solution condition
            if(l1 <= r2 && l2 <= r1){
                int n = n1 + n2;
                if(n % 2) return max(l1, l2);
                else {
                    double ans = ((double)(max(l1, l2) + min(r1, r2)))/2.00;
                    return ans;
                }
            }
            // Sample space reduction
            // Case 1 - too many elements from arr1
            else if(l1 > r2){
                // Take lesser elements from arr1
                high = mid1 - 1;
            }
            // Case 2 - too few elements from arr1
            else low = mid1 + 1;
        }
        return 0.00;
    }
};