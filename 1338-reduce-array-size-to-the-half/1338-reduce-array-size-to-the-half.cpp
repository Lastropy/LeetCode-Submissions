class Solution {
public:
         int minSetSize(vector<int>& arr) {
            int n = arr.size(), tar = arr.size() / 2;
            unordered_map<int, int> mp;
            vector<int> freq(n+1, 0);

            for(int i : arr) mp[i]++;
            for(auto [k,v]: mp) freq[v]++;

            int ptr = freq.size() - 1 , ans = 0 ;

            while(n > tar){
                if(freq[ptr]){
                    int required = ceil((double)(n - tar) / ptr);
                    int have = freq[ptr];
                    int times = min(required, have);
                    ans += times;
                    n -= (times * ptr);
                }
                ptr--;
            }       
            return ans;
        }
//     int minSetSize(vector<int>& arr) {
//         unordered_map<int, int> mp;
//         vector<int> freq;

//         for(int i : arr) mp[i]++;
//         for(auto [k,v]: mp) freq.push_back(v);
        
//         sort(freq.begin(), freq.end());
        
//         int n = arr.size(), tar = arr.size() / 2, ptr = freq.size() - 1;

//         while(n > tar)
//             n -= freq[ptr--];

//         return freq.size() - 1 - ptr;
//     }
};