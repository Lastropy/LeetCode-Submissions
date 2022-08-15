class Solution {
public:
    int romanToInt(string s) {
        
        int val = 0;

        int prev = -1;

        map<char, int> mp{{'I', 1},
                          {'V', 5},
                          {'X', 10},
                          {'L', 50},
                          {'C', 100},
                          {'D', 500},
                          {'M', 1000}};

        for(int i = s.size() - 1; i >= 0; i--){

            int dig = mp[ s[i] ];

            if(dig >= prev)     val += dig;

            else                val -= dig;

            prev = mp[ s[i] ];
        }

        return val;
    }
};