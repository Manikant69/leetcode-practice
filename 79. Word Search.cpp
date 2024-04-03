class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int index, vector<vector<bool>>&vis)
    {
        if(index >= word.length()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j] == true || board[i][j] != word[index]){
            return false;
        }

        vis[i][j] = true;
        index++;
        bool ans = dfs(board, word, i+1, j, index, vis)
                    || dfs(board, word, i-1, j, index, vis)
                    || dfs(board, word, i, j+1, index, vis)
                    || dfs(board, word, i, j-1, index, vis);
        vis[i][j] = false;
        return ans; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();

        vector<vector<bool> > vis(r,vector<bool>(c, 0));
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                int index = 0;
                if(dfs(board, word, i, j, index, vis)){
                    return true;
                }
            }
        }

        return false;
    }
};
