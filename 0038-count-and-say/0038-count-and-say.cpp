class Solution {
public:
    string countNsay(string s){
        string temp = "";
        char prev = s[0];
        int count = 0;
        for(int j = 0; j < s.size(); j++){
            if(prev == s[j]){
                count++;
            } else {
                temp += string(1, count+'0') + string(1, prev);
                count = 1;
                prev = s[j];
            }
        }
        temp += string(1, count+'0') + string(1, prev);
        return temp;
    }
    
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++)
            ans = countNsay(ans);
        return ans;
    }
};