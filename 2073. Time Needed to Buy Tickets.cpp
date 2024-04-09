class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;

        for(int i=0; i<tickets.size(); i++)
        {
            if(tickets[i] < tickets[k]){
                ans += tickets[i];
            }
            else if(i <= k){
                ans += tickets[k];
            }
            else{
                ans += (tickets[k] - 1);
            }
        }

        return ans;
    }
};
