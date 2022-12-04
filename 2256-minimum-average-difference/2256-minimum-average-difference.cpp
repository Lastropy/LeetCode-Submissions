class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        int n = a.size();
        vector<int> a1(n, 0), a2(n, 0);
        
        a1[0] = a[0];
        a2[n-1] = a[n-1];
        
        long sum = 0;
        for(int i = 0; i  < n; i++)
        {
            sum += a[i];
            a1[i] = (sum)/(i+1);
            
        }
        sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += a[i];
            a2[i] = (sum)/(n - i);
        }

        int ans = INT_MAX, pos = 0;
        for(int i = 0;  i < n; i++){
            if(i == n-1){
                if(ans > abs(a1[i])){
                    ans = abs(a1[i]);
                    pos = i; 
                }
                continue;
            }
            if(ans > abs(a1[i] - a2[i+1])){
                ans = abs(a1[i] - a2[i+1]);
                pos = i;      
            }
        }
        return pos;
    }
};