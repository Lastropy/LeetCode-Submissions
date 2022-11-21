class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int erow = entrance[0], ecol = entrance[1];
        queue<vector<int>> q;
        int ans = 0;
        maze[erow][ecol] = '+';
        for(q.push({erow, ecol}); !q.empty(); ans++){
            int size = q.size();
            for(int i = 0 ; i < size; i++, q.pop()){
                int row = q.front()[0], col = q.front()[1];
                if((row == m-1 || row == 0 || col == 0 || col == n - 1) && ans)
                    return ans;
                
                if(row + 1 < m && maze[row + 1][col] != '+'){
                    q.push({row+1, col});
                    maze[row+1][col] = '+';
                }
                if(col + 1 < n && maze[row][col + 1] != '+') {
                    q.push({row, col + 1});
                    maze[row][col + 1] = '+';
                }
                if(row - 1 >= 0 && maze[row - 1][col] != '+') {
                    q.push({row - 1, col});
                    maze[row - 1][col] = '+';
                }
                if(col - 1 >= 0 && maze[row][col - 1] != '+'){
                    q.push({row, col - 1});
                    maze[row][col - 1] = '+';
                } 
            }
        }

        return -1;
    }
};