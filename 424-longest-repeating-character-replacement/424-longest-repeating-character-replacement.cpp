class Solution {
public:
    int sw(string s, int k ,char c){
        int i = 0, j = 0;
        int n = s.size();
        int count = 0;
        int ans = 0;
        for(i = 0, j = 0; j < n ; j++){
            if(s[j] != c)
                count++;
            while(i < n && count > k){
                if(s[i]!= c)
                    count--;
                i++;
            }
            if( count <= k)
                ans = max(ans, j - i + 1);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int arr[26];
        memset(arr,0, sizeof(arr));
        for(char c: s)
            arr[c-'A'] |= 1;
        int ans = 0;
        for(int i  = 0; i < 26; i++){
            if(arr[i]){
                ans = max(ans , sw(s,k,'A'+i));
            }
        }
        return ans;
    }
};