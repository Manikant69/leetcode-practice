class Solution {
private:
    bool isPossible(vector<int>& piles, int h, int m)
    {
        int ans = 0;
        for(int i=0; i<piles.size(); i++)
        {
            ans += (piles[i]/m);
            if(piles[i]%m != 0){
                ans++;
            }

            if(ans > h){
                return false;
            }
        }

        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
