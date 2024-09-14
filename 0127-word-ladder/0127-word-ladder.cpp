class Solution {
public:
    int diff(string &s1, string &s2){
        int len = s1.size();
        int diff = 0;
        for(int i = 0; i < len && diff < 2; i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff;
    }
    
    int ladderLength(string b, string e, vector<string>& a) {
        int n = a.size(), m = b.size();
        int pos_src = -1, pos_dest = -1;
        for(int i =0; i < n; i++){
            if(a[i] == b) pos_src = i;
            if(a[i] == e) pos_dest = i;
        }
        if(pos_dest == -1) return 0;
        if(pos_src == -1){
             a.push_back(b);
             pos_src = n++;
        }
        
        vector<vector<int>> adj(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(diff(a[i],a[j]) == 1){
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
        }
        
        queue<int> q;
        q.push(pos_src);
        vector<int> dist(n, 1e9);
        dist[pos_src] = 0;
        
        while(!q.empty()){
            int siz = q.size();
            for(int i = 0; i< siz; i++){
                auto tp = q.front(); q.pop();
                for(int j = 0; j < n; j++){
                    if(adj[tp][j]){
                        if(dist[j] > dist[tp] + 1){
                            dist[j] = dist[tp] + 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return dist[pos_dest] >= 1e9 ? 0 : dist[pos_dest] + 1;
        
    }
};