class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int right = 0, left = 0, n = nums.size();
	int maxLen = 0, cntZeros = 0;

	while(right < n){
		if(nums[right] == 0){
			cntZeros++;
		}

		//m is not sufficient to make this length as all ones
		while(cntZeros > k){
			if(nums[left] == 0){
				cntZeros --;
			}
			left++; //reduce the 0 from the starting
		}

		maxLen = max(maxLen, right - left + 1);

		right++;
	}

	return maxLen;
    }
};
