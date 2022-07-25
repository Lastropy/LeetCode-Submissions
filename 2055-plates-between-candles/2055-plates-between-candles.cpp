class Solution {
public:
    int upper(vector<vector<int>> &pos, int st, int en, int &tar ){
        if(st > en) return -1;
        int mid = st + (en - st) / 2;
        if(pos[mid][0] == tar)
            return mid;
        else if(pos[mid][0] > tar){
            int better = upper(pos, st, mid - 1, tar);
            if(better != -1)
                return better;
            return mid;
        }
        return upper(pos, mid + 1, en, tar);
    }
    int lower(vector<vector<int>> &pos, int st, int en, int &tar ){
        if(st > en) return -1;
        int mid = st + (en - st) / 2;
        if(pos[mid][1] == tar)
            return mid;
        else if(pos[mid][1] < tar){
            int better = lower(pos, mid + 1, en, tar);
            if(better != -1)
                return better;
            return mid;
        }
        return lower(pos, st, mid - 1, tar);
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries)     {
        int last_can = -1;
        int cf = 0;
        vector<vector<int>> pos;
        for(int i = 0; i < s.size(); i++){
            if(s[i]  == '|'){
                if(last_can != -1){
                    cf += i - last_can - 1;
                    pos.push_back(vector<int>({last_can, i, cf}));
                    // cout << pos.back()[0] << "," << pos.back()[1] << " = "<< pos.back()[2]<< endl;
                }
                last_can = i;
            }
        }
        vector<int> ans;
        for(auto q: queries){
            int ub = upper(pos, 0 , pos.size() - 1, q[0]);
            int lb = lower(pos, 0 , pos.size()-1, q[1]);
            int curr=  0 ;
            if(ub != -1 && lb != -1 && lb >= ub)
                curr =  pos[lb][2] - (ub != 0 ? pos[ub-1][2]: 0);
            ans.push_back(curr);
        }
        return ans;
    }
};