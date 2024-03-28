class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int maxi = INT_MIN;
        int j = 0;

        for(int i=0; i<nums.size(); i++)
        {
            int val = nums[i];

            mpp[val]++;

            while(j<=i && mpp[val] > k){
                mpp[nums[j]]--;
                j++;
            }

            if(maxi < (i - j + 1)){
                maxi = i - j + 1;
            }
        }

        return maxi;
    }
};
