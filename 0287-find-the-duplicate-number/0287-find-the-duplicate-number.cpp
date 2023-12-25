class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        // for(int i = 0; i < n; i++){
        //     while(a[i] != i+1 && a[a[i] - 1] != a[i]){
        //         swap(a[i], a[a[i]-1]);
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     if(a[i] != i+1){
        //         return a[i];
        //     }
        // }
        // return -1;
        int ans = -1;
        for(int i = 0; i < n; i++){
            int idx = a[i] < 0 ? -1 * a[i] : a[i];
            idx--;
            if(a[idx] > 0)
                a[idx] *= -1;
            else{
                ans = idx + 1;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            a[i] = (a[i] < 0? -a[i]: a[i]); 
        }
        return ans;
        
    }
};