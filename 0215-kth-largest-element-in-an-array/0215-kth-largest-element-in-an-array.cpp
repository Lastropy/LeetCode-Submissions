class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end(), greater<int>());
        return arr[k - 1];
    }
};