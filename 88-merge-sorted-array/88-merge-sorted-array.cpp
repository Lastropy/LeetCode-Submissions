class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
       for(int i = m; i < a.size(); i++){
           a[i] = b[i-m];
       }
        sort(a.begin(), a.end());
    }
};