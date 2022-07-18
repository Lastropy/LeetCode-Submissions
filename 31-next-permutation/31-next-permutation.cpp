class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int j;
        for(j = n-1; j> 0; j--){
            if(a[j] > a[j-1])
                break;
        }
        int pos1= j-1;
        if(pos1 == -1)
        {
            sort(a.begin(),a.end());
            return;
        }
        int i;
        for(i = n - 1; i > 0; i--){
            if(a[i] > a[pos1])
                break;
        }
        swap(a[i],a[pos1]);
        reverse(a.begin()+pos1+1,a.end());
        return;
    }
};