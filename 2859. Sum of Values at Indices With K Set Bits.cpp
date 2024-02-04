class Solution {
private:
    int countBits(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n = (n &(n-1));
        }
        return cnt;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
       int sum = 0;

       for(int i=0; i<nums.size(); i++)
       {
           if(countBits(i) == k){
               sum += nums[i];
           }
       } 

       return sum;
    }
};
