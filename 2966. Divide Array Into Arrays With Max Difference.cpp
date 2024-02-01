class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > ans;
        int firstEle = nums[0];

        vector<int> temp;
        temp.push_back(firstEle);

        for(int i=1; i<nums.size(); i++)
        {
            if((nums[i] - firstEle) <= k && temp.size() < 3){
                temp.push_back(nums[i]);
            }
            else{
                if(temp.size() < 3){
                    return {};
                }
                
                ans.push_back(temp);
                temp = {};
                firstEle = nums[i];
                temp.push_back(firstEle);
            }
        }

        ans.push_back(temp);

        return ans; 
    }
};
