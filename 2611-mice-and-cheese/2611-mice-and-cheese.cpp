class Solution {
    public:
#define ll 
int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
    long long n = r1.size(), ans = 0;
    for(int i = 0; i < n; i++){
        ans += r2[i];
        r1[i] -= r2[i];
    }
    
    // Finds biggest k elements in array in O(N)
    nth_element(begin(r1), begin(r1) + k, end(r1), greater<int>());
    
    return accumulate(begin(r1), begin(r1)+ k, ans);
}
};