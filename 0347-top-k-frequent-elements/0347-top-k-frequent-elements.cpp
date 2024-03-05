class Solution {
public:
    int partition(vector<int> &arr, unordered_map<int, int> &mp, int lo, int hi){
        int s = lo, e = hi - 1, fpEle = mp[arr[hi]];
        while(s <= e){
            int f1 = mp[arr[s]], f2 = mp[arr[e]];
            if(f1 < fpEle && f2 > fpEle){
                swap(arr[s++], arr[e--]);
            }
            if(f1 >= fpEle) s++;
            if(f2 <= fpEle) e--;
        }
        swap(arr[s], arr[hi]);
        return s;
    }
    
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int, int> mp;
        vector<int> arr;
        arr.reserve(a.size());
        
        for(int i: a){
            mp[i]++;
            if(mp[i] == 1) arr.push_back(i);
        }
        
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int idx = partition(arr, mp, lo, hi);
            if(idx == k - 1){
                arr.resize(k);
                return arr;
            } else if( idx < k - 1){
                lo = idx + 1;
            } else {
                hi = idx - 1;
            }
        }
        return {};
    }
};