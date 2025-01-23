class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>RowCount(m, 0);
        vector<int>ColCount(n, 0);
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    RowCount[i] += 1;
                    ColCount[j] += 1;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && (RowCount[i] > 1 || ColCount[j] > 1))
                {
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};