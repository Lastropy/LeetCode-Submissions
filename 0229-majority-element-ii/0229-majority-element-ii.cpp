class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size(), cnt1 = 0, cnt2 = 0, el1= INT_MIN, el2 = INT_MIN;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && a[i] != el2) el1 = a[i];
            else if(cnt2 == 0 && a[i] != el1) el2 = a[i];
            
            if(a[i] == el1) cnt1++;
            else if(a[i] == el2) cnt2++;
            else cnt1--, cnt2--;
        }
        int freq1 = 0, freq2 = 0;
        for(int i: a){
            if(i == el1) freq1++;
            else if(i == el2) freq2++;
        }
        if(freq1 > (n/3)) ans.push_back(el1);
        if(freq2 > (n/3)) ans.push_back(el2);
        return ans;
    }
};