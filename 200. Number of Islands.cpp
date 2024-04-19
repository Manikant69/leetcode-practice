class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool> >&vis)
    {
        vis[r][c] = 1;

        queue<pair<int, int> > q;
        q.push({r, c});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse all it's neighbours and mark them if it's a land
            if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col] == '1')
            {
               q.push({row-1, col});
               vis[row-1][col] = 1;
            }
            if(row+1 < n && !vis[row+1][col] && grid[row+1][col] == '1')
            {
               q.push({row+1, col});
               vis[row+1][col] = 1; 
            }
            if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1] == '1')
            {
                q.push({row, col-1});
                vis[row][col-1] = 1;
            }
            if(col+1 < m && !vis[row][col+1] && grid[row][col+1] == '1')
            {
                q.push({row, col+1});
                vis[row][col+1] = 1;
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool> > vis (n, vector<bool>(m, 0));

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }

    return cnt;

    }

};
