class Solution {
public:
    vector <int> isc[501];
    long dis[501][501];
    int n,tar,as;
    bool jc(string x,string y){
        int v=0;
        for(int i=0;i<x.size();++i)
            if(x[i]!=y[i])++v;
        return v==1;
    }
    vector<vector<string>> findLadders(string bW, string eW, vector<string>& wL) {
        vector<vector<string>> rt;
        n=wL.size();
        memset(dis,0x3f,sizeof(dis));
        for(int i=0;i<n;++i){
            if(wL[i]==eW)tar=i+1;
            if(jc(wL[i],bW)){
                isc[0].push_back(i+1);
                dis[0][i+1]=dis[i+1][0]=1;
            }
            for(int j=i+1;j<n;++j)
                if(jc(wL[i],wL[j])){
                    isc[i+1].push_back(j+1);
                    isc[j+1].push_back(i+1);
                    dis[j+1][i+1]=dis[i+1][j+1]=1;
                }
        }
        if(tar==0)return rt;
        for(int k=0;k<=n;++k)
            for(int i=0;i<=n;++i)
                for(int j=0;j<=n;++j)
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
        as=dis[0][tar];
        queue <vector <int>> q;
        vector <int> v;
        v.push_back(0);
        q.push(v);
        dis[tar][tar]=0;
        while(!q.empty()){
            v=q.front();q.pop();
            int tp=v.back();
            if(tp==tar){
                vector <string> vs;
                vs.push_back(bW);
                for(int i=1;i<=as;++i)
                    vs.push_back(wL[v[i]-1]);
                rt.push_back(vs);
                continue;
            }
            for(int i=0;i<isc[tp].size();++i){
                if(dis[isc[tp][i]][tar]==dis[tp][tar]-1){
                    vector <int> tv=v;
                    tv.push_back(isc[tp][i]);
                    q.push(tv);
                }
            }
        }
        return rt;
    }
};