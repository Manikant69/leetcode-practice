class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans[0] = 1;
        long val = 1;

        for(int i=1; i<=rowIndex; i++)
        {
            int t = rowIndex - i + 1;
            val = val * t/i;

            ans[i] = val;
        }

        return ans;
    }
};
