class Solution {
public:
    string makeGood(string s) {
//         if(s.size() == 1) return s;
//         int p1, p2;
//         for(p1 = 0, p2 = 0; p2 < s.size(); p2++){
//             if(p1 > 0 && abs(s[p1 - 1] - s[p2]) == 32)
//                 --p1;
//             else
//                 s[p1++] = s[p2];
//         }
        
//         return s.substr(0, p1);
        stack<char> st;
        for(int i =0; i < s.size(); i++){
            if(!st.empty() && abs(st.top() - s[i]) == 32)
                st.pop();
            else
                st.push(s[i]);
        }
        
        s = "";
        while(!st.empty())
            s += st.top(), st.pop();
        reverse(s.begin(), s.end());
        return s;
    }
};