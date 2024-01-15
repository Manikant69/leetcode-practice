class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpp;
        for(int i = 0; i<matches.size(); i++)
        {
            if(!mpp[matches[i][0]]){
                mpp[matches[i][0]] = 0;
            }
            mpp[matches[i][1]]++;
        }

        vector<vector<int> > ans;
        vector<int> noDefeat, oneDefeat;

        for(auto it : mpp)
        {
            if(it.second == 1){
                oneDefeat.push_back(it.first);
            }
            else if(it.second == 0){
                noDefeat.push_back(it.first);
            }
        }

        ans.push_back(noDefeat);

        ans.push_back(oneDefeat);

        return ans;
    }
};
