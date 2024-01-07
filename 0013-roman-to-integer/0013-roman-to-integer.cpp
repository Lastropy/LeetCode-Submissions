class Solution {
public:
    int romanToInt(string s) {
        vector<vector<string>> roman = {
                                {"","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},                                     {"","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                {"","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},                                     {"","M", "MM", "MMM", "MMMM"}
                              };
        
        int ans = 0;
        for(int i = 3; i>=0; i--){
            for(int j = roman[i].size() - 1; j >= 1; j--){
                int found = s.find(roman[i][j]);
                if(found != 0) continue;
                // cout << roman[i][j] << " -> "<< j * pow(10, i) << endl;
                ans += j * pow(10, i);
                s = s.substr(roman[i][j].size());
                break;
            }
        }
        return ans;
    }
};