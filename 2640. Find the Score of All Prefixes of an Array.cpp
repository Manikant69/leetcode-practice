class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long max = 0;
        long long sum = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > max){
                max = nums[i];
            }

            if(i != 0)
                sum = ans.back();

            ans.push_back(sum + max + nums[i]);

        }

        return ans;
    }
};
