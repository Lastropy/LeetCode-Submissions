class Solution {
public:
    int findDuplicate(vector<int>& a) {
        for(int i = 0; i < a.size(); i++){
            while(a[i] != i+1 && a[a[i] - 1] != a[i]){
                swap(a[i], a[a[i]-1]);
            }
        }
        for(int i = 0; i < a.size(); i++){
            if(a[i] != i+1){
                return a[i];
            }
        }
        return -1;
        
    }
};