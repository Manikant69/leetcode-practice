class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int j=0;
        while(j<nums.size())
        {
            for(int i=1; i<nums.size()-j; i++)
            {
                int sum = nums[i-1] + nums[i];
                nums[i-1] = sum%10;
            }

            j++;
        }

        return nums[0];
    }
};
