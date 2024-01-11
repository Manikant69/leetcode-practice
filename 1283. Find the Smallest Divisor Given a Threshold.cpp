class Solution {
private:
    bool isPossible(vector<int>& arr,int mid,  int limit)
    {
        int ans = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            ans += arr[i]/mid;
            if(arr[i]%mid) ans++;
        }

        return ans <= limit;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    int ans = 0;
	int s = 1, e = *max_element(nums.begin(), nums.end());

	while(s <= e)
	{
		int mid = s + (e - s)/2;

		if(isPossible(nums, mid, threshold)){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}

	return ans;
    }
};
