class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            string temp = "";
            char prev = ans[0];
            int count = 0;
            for(int j = 0; j < ans.size(); j++){
                if(prev == ans[j]){
                    count++;
                } else {
                    temp += string(1, count+'0') + string(1, prev);
                    count = 1;
                    prev = ans[j];
                }
            }
            temp += string(1, count+'0') + string(1, prev);
            ans = temp;
        }
        return ans;
    }
};