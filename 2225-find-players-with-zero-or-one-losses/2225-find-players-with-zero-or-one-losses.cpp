class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> ln;
        set<int> lo;
        set<int> lt;
        for(auto v: matches)
        {
            int w = v[0],l=v[1];
            if(lo.find(w) == lo.end() && lt.find(w) == lt.end())
            {
                ln.insert(w);
            }
            if(lo.find(l) != lo.end())
            {
                lo.erase(l);
                lt.insert(l);
            }
            else if(ln.find(l) != ln.end())
            {
                ln.erase(l);
                lo.insert(l);
            }
            else if(lt.find(l) == lt.end() && ln.find(l) == ln.end() && lo.find(l) == lo.end())
            {
                lo.insert(l);
            }
        }
        vector<int> n(ln.begin(),ln.end());
        vector<int> o(lo.begin(),lo.end());
        return vector<vector<int>>({n,o});
    }
};