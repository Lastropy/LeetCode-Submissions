class Solution {
public:
    void construct_z_arr(string s, vector<int> &z){
        int len = s.length();
        int l = 0, r = 0;
        for(int i =1; i < len; i++){
            if(i > r){
                l = i, r = i;
                while(r < len && s[r] == s[r-l])
                    r++;
                r--;
                z[i] = r - l + 1;
            }
            else{
                int idx = i-l;
                if(z[idx] < r - i + 1)
                    z[i] = z[idx];
                else{
                    l = i;
                    while( r < len && s[r] == s[r - l])
                        r++;
                    r--;
                    z[i] = r - l + 1;
                }
                
            }
        }
    }
    int strStr(string haystack, string needle) {
        string com = needle;
        com += "$";
        com += haystack;
        vector<int> z(com.size(), 0);
        construct_z_arr(com,z);
        for(int i = 0; i < z.size(); i++){
            // cout << z[i] << ",";
            if(z[i] == needle.size())
                return i - needle.size() -1;
        }
        return -1;
    }
};