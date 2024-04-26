class Solution {
private:
    void solve(vector<int>& candidates, int target, int index, vector<int>&temp, vector<vector<int>> &ans)
    {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || index >= candidates.size()){
            return;
        }

        //include
        temp.push_back(candidates[index]);
        solve(candidates, target-candidates[index], index, temp, ans);
        //backtrack
        temp.pop_back();


        //exclude
        solve(candidates, target, index+1, temp, ans);
         
    } 
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};
