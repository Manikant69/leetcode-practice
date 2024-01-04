class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(auto it : nums){
            mpp[it]++;
        }
        int ans = 0;

        for(auto it : mpp){
            if(it.second == 1){
                return -1;
            }
            else if(it.second % 3 == 0){
                ans += (it.second / 3);
            }
            else{
                int val = it.second;

                ans += (val / 3);
                val = val % 3;

                if(val == 1){
                    ans--;
                    val += 3;
                }

                ans += (val / 2);
            }
        }

        return ans;
    }
};
