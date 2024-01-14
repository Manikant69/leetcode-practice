class Solution {
private:
    int findMaxElement(vector<vector<int>> &g, int n, int col)
    {
        int index = -1;
        int maxValue = -1;

        for(int i=0; i<n; i++)
        {
            if(g[i][col] > maxValue)
            {
                index = i;
                maxValue = g[i][col];
            }
        }

        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        int row = findMaxElement(mat, n, mid);

        int leftVal = mid > 0 ? mat[row][mid-1] : -1;
        int rightVal =  mid + 1 < m ? mat[row][mid+1] : -1;
        int currVal = mat[row][mid];//no need to check for top and bottom because this is the max value in that column

        if(leftVal < currVal && currVal > rightVal){
            return {row, mid};
        }
        else if(leftVal > currVal){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }  

    return {-1, -1};  
    }
};
