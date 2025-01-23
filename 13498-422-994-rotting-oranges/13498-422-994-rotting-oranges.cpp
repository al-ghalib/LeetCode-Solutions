// TC --> O(m*n) * 4
// SC --> O(m*n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();        
        
        queue<pair<int, int>> q;  // store the coordinates of cells
        
        int fresh = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j}); // rotten
            }
        }
        
        if(fresh == 0) return 0; // all oranges are already rotten

        int time = 0;
        
        vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        while(!q.empty() && fresh != 0)
        {
            int N = q.size();
            
            while(N--)
            {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();

                for(auto &dir : directions)
                {
                    int new_x = x + dir.first;
                    int new_y = y + dir.second;
                    
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1)
                    {
                        grid[new_x][new_y] = 2;
                        fresh--;
                        q.push({new_x, new_y});
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};