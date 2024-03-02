class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            sort(grid[i].begin(), grid[i].end());
        }

        int col = m - 1;
        int ans = 0;
        
        while (col >= 0) {
            int max = INT_MIN;
            for (int i = 0; i < n; i++) {
                if(grid[i][col] > max){
                    max = grid[i][col];
                }
            }

            ans += max;
            col--;
        }

        return ans;
    }
};
