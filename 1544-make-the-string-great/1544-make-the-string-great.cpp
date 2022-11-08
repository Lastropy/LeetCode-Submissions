class Solution {
public:
    string makeGood(string s) {
        string prev = "";
        string curr = s;
        while(curr != prev ){
            prev = curr;
            for(int i=1; i < curr.size(); i++){
                if(tolower(curr[i]) == tolower(curr[i-1])){
                    if((isupper(curr[i]) && islower(curr[i-1])) ||
                        islower(curr[i]) && isupper(curr[i-1]))
                        curr.erase(i-1,2);
                }
            }
        }
        return curr;
    }
};