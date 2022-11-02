class Solution {
public:
    int diff(string &a, string &b){
        if(a== b) return 0;
        int ans = 0;
        for(int i =0; i < 8 && ans < 2; i++)
            ans += (a[i] != b[i]);
        return ans;  
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if(!st.count(end)) return -1;
        
        queue<string> q;
        int steps = 0;
    
        for(q.push(start); !q.empty();){
            int size = q.size();
            for(int i = 0; i < size; i++, q.pop()){
                
                string curr = q.front();
                
                if(curr == end) return steps;
                
                st.erase(curr);
                
                for(string s: st)
                    if(diff(curr, s) == 1)
                        q.push(s);
                
            }
            steps++;
        }
        return -1;
        
    }
};