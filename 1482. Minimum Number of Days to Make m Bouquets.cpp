class Solution {
private:
    int countBouquet(vector<int>& bloomDay, int mid, int k){
        int cnt = 0, ans = 0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else{
                ans += (cnt/k);
                cnt = 0;
            }
        }

        ans += (cnt/k);

        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), ans = -1;
        long long total = m * 1ll * k * 1ll;

        if(total > n) return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        while(s <= e)
        {
            int mid = s + (e - s)/2;

            int val = countBouquet(bloomDay, mid, k);

            if(val >= m){
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
