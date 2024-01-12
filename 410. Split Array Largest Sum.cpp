class Solution {
private:
    bool isPossible(vector<int> &a,int maxSum, int k)
    {
        int sum = a[0];
        int cntSub = 1;

        for(int i=1; i<a.size(); i++)
        {
            sum += a[i];

            if(sum > maxSum){
                cntSub++;
                sum = a[i];
            }

            if(cntSub > k){
                return false;
            }
        }

        return true;
    }
public:
    int splitArray(vector<int>& a, int k) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(isPossible(a, mid, k))
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

    return low;
    }
};
