class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();   
        
        vector<vector<int>> height(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isWater[i][j] == 1)
                {
                    height[i][j] = 0;    // bfs source starting
                    q.push({i, j});
                } 
                
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        while(!q.empty())
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
                    
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && height[new_x][new_y] == -1)
                    // if height unassigned
                    {
                        height[new_x][new_y] = height[x][y] + 1;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        return height;
    }
};