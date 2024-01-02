class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        

        map<int,int> freqMp;

        for(auto i: nums){
            freqMp[i]++;
        }

        while(freqMp.size()){
            vector<int>temp;

            for(auto &v : freqMp){
                temp.push_back(v.first);
                v.second--;
            }

            for(auto i : temp){
                if(freqMp[i] <= 0){
                    freqMp.erase(i);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
