class Solution {
public:
    int majorityElement(vector<int>& a) {
        int cnt = 0;
        int n = a.size();
        int el;
        for(int i = 0; i < n; i++){
            if(cnt == 0) el = a[i];
            if(el == a[i]) cnt++;
            else cnt--;
        }
        int freq = 0;
        for(int i: a){
            if(i == el)
                freq++;
        }
        return (freq > (n/2) ? el : -1);
    }
};