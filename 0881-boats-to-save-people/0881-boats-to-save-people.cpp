class Solution {
public:
    int numRescueBoats(vector<int>& a, int tar) {
        int nob = 0;
        int sum = 0;
        sort(begin(a), end(a));
        for(int i= 0, j = a.size() - 1; i <= j;){
            if(a[i] + a[j] <= tar)
            {
                nob++;
                i++;
                j--;
            }
            else{
                nob++;
                j--;
            }
        }
        return nob;
    }
};