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
        int s = 1, e = INT_MIN;
        for(int i = 0; i < a.size(); i++){
            e = max(a[i], e);
        }
        
        e = e + 1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(satisfiesThreshold(a, mid, t)){
                cout << "yes" << endl;
                ans = mid;
                e = mid - 1;
            } else {
                cout << "no" << endl;
                s = mid + 1;
            }
        }
        return ans;
    }
};