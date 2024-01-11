class Solution {
private:
    int countDays(vector<int> &weights, int maxLoad)
    {
        int load = 0;
        int cntDays = 1;

        for(int i=0; i<weights.size(); i++)
        {
            load += weights[i];

            if(load > maxLoad){
                load = weights[i];
                cntDays++;
            }
        }

        return cntDays;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
    int s = *max_element(weights.begin(), weights.end());
    int e = accumulate(weights.begin(), weights.end(), 0);

    int ans = -1;

    while(s <= e)
    {
        int mid = s + (e - s)/2;

        int noOfDays = countDays(weights, mid);

        if(noOfDays <= days){
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
