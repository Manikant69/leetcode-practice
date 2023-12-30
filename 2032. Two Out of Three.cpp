class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        vector<int> ans;
        unordered_set<int> s;

        unordered_map<int, int> mp1, mp2;

        for(int i=0; i<nums1.size(); i++)
        {
            mp1[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++)
        {
            mp2[nums2[i]]++;
            if(mp1.find(nums2[i]) != mp1.end()){
                s.insert(nums2[i]);
            }
        }

        for(int i=0; i<nums3.size(); i++){
            if(mp1.find(nums3[i]) != mp1.end() || mp2.find(nums3[i]) != mp2.end()){
                s.insert(nums3[i]);
            }
        }

        for(auto v : s){
            ans.push_back(v);
        }

        return ans;
    }
};
