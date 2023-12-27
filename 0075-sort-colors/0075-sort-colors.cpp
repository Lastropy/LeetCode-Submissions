class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        // valid according to the rules
        int low = 0, mid = 0, high = n-1;
        while(mid <= high){
            if(a[mid] == 0){
                swap(a[mid], a[low]);
                low++;
                mid++;
            } else if(a[mid] == 2){
                swap(a[mid], a[high]);
                high--;
            } else {
                mid++;
            }
        }
    }
};