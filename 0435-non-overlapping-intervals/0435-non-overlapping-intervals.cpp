class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& a) {
		if(a.size()==0) return 0;       
        sort(a.begin(),a.end(),[&](const vector<int> &p,const vector<int> &q) {
            return p[1] < q[1];
        });
        
		vector<int> prev= a[0];
		int ans = -1;      
		for(auto i: a) {
			if(prev[1] > i[0]) 
                ans++;                
			else 
                prev = i;
		}
		return ans;
	}
};