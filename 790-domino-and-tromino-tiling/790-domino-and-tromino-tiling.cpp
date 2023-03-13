class Solution {
public:
   int numTilings(int N) {
    if(N <= 2) return N;
    int md=1e9 + 7;
    vector<long long> v(N+1,0);
    v[0] = 1, v[1]=1,v[2]=2;
    for(int i=3; i<=N; ++i)
        v[i]=(2*v[i-1]+v[i-3])%md; 
    return v[N];
}};