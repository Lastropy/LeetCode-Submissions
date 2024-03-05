class Solution {
public:
    int partition(vector<int> &arr, int lo, int hi){
        int pEle = arr[hi], s = lo, e = hi - 1;
        while(s <= e){
            if (arr[s] < pEle && arr[e] > pEle) {
                swap(arr[s++], arr[e--]);
            }
            if (arr[s] >= pEle) {
                s++;
            }
            if (arr[e] <= pEle) {
                e--;
            }
        }
        swap(arr[hi], arr[s]);
        return s;
    }
    
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while(true){
            int pos = partition(arr, lo, hi);
            if(pos == k - 1){
                return arr[pos];
            } else if(pos < k - 1){
                lo = pos + 1;
            } else {
                hi = pos - 1;
            }
        }
        return -1;
    }
};