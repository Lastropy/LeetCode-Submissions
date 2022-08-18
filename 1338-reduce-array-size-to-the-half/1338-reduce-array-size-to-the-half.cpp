class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> freq;

        for(int i : arr) mp[i]++;
        for(auto [k,v]: mp) freq.push_back(v);
        
        sort(freq.begin(), freq.end());
        
        int n = arr.size(), tar = arr.size() / 2, ptr = freq.size() - 1;

        while(n > tar)
            n -= freq[ptr--];

        return freq.size() - 1 - ptr;
    }
};