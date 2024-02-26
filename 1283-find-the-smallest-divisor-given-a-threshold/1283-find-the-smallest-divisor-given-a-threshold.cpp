class Solution {
public:
    bool satisfiesThreshold(vector<int> &a, int mid, int t){
        int ans = 0;
        for(int i =0; i < a.size(); i++){
            ans += ceil((a[i] * 1.00)/ mid);
        }
        return (ans <= t);
    }
    
    int smallestDivisor(vector<int>& a, int t) {
        int s = 1;
        int e = (*max_element(a.begin(), a.end())) + 1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(satisfiesThreshold(a, mid, t)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};