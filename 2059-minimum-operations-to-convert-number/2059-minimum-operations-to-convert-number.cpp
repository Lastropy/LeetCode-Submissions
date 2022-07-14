class Solution {
public:
    int f(vector<int> &a, int s, int g){
        queue<int> q;
        q.push(s);
        int steps = 0;
        set<int> visited;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int pos = q.front(); q.pop();
                if(pos == g) return steps;
                if(pos < 0 || pos > 1000 || visited.find(pos) != visited.end()  ) continue;
                for(int j = 0; j < a.size(); j++){
                    q.push(pos + a[j]);
                    q.push(pos - a[j]);
                    q.push(pos ^ a[j]);
                }
                visited.insert(pos);
            }
            steps++;
        }
        return -1;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {
        return f(nums, start, goal);
    }
};