class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colSum) {

        int twoElementInColumn = 0;
        int totalSum = 0;

        for(int i=0; i<colSum.size(); i++)
        {
            totalSum += colSum[i];
            if(colSum[i] == 2){
                twoElementInColumn++;
            }
        }

        if(totalSum != (upper + lower) || (twoElementInColumn > upper) || (twoElementInColumn > lower))
        {
            return {};
        }

        vector<vector<int> > ans(2);
        
        for(int i=0; i<colSum.size(); i++)
        {
            if(colSum[i] == 2)
            {
                ans[0].push_back(1);
                ans[1].push_back(1);
                upper--;
                lower--;
                twoElementInColumn--;
            }
            else if(colSum[i] == 1)
            {
                if(upper != 0 && upper > twoElementInColumn)
                {
                    ans[0].push_back(1);
                    ans[1].push_back(0);
                    upper--;
                }
                else{
                    ans[1].push_back(1);
                    ans[0].push_back(0);
                    lower--;
                }                
            }
            else{
                ans[0].push_back(0);
                ans[1].push_back(0);
            }
        }

        return ans;
    }
};
