class Solution {
private:
    void merge(vector<int>&a , int s, int mid, int e)
    {
        int i = s, j = mid + 1;
        int n = e - s + 1;
        int temp[n];
        int k = 0;

        while(i<=mid && j<=e)
        {
            if(a[i] > a[j]){ 
                temp[k++] = a[j];
                j++;
            }
            else{
                temp[k++] = a[i];
                i++;
            }
        }

        while(i<=mid)
        {
            temp[k++] = a[i];
            i++;
        }
        while(j <= e){
            temp[k++] = a[j];
            j++;
        }

        for(int i=s; i<=e; i++)
        {
            a[i] = temp[i - s];
        }
    }

    int countPairs(vector<int>&a , int s, int mid, int e)
    {
        int j = mid + 1;
        int cnt = 0;

        for(int i=s; i<=mid; i++)
        {
            while(j<=e && a[i] >(long long)2*a[j])
                j++;

            cnt += (j - (mid+1));
        }

        return cnt;
    }

    int mergeSort(vector<int>&a, int s, int e)
    {
        int cnt = 0;

        if(s >= e){
            return cnt;
        }

        int mid = (s + e)/2;

        cnt += mergeSort(a, s, mid);
        cnt += mergeSort(a, mid+1, e);

        cnt += countPairs(a, s, mid, e);

        merge(a, s, mid, e);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
