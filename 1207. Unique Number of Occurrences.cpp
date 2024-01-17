class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(), arr.end());

        for(int i=0; i<arr.size();)
        {
            int cnt = 1, j = i+1;
            while(j<arr.size() && arr[i] == arr[j]){
                j++;
                cnt++;
            }
            i = j;
            ans.push_back(cnt);
        }

        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size()-1; i++)
        {
            if(ans[i] == ans[i+1]){
                return false;
            }
        }

        return true;
    }   
   
};
