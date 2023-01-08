class Solution {
public:
      int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        float res=0;
        float ans=0;
        for(int i=0;i<n;i++){
            map<float,float>mp;
            map<float,float>m;
            float maxi=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                float t=points[i][0]-points[j][0];
                if(t==0){
                    m[points[i][0]]++;
                    ans=max(ans,m[points[i][0]]);
                   
                    
                    continue;
                }
                
                float r=points[i][1]-points[j][1];
                
                mp[(r/(float)t)]++;
                maxi=max(maxi,mp[(r/(float)t)]);
                
    
            }
            res=max(res,maxi);
        }
        return max(res+1,ans+1);
        
    }
};