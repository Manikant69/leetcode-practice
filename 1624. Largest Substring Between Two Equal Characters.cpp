class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int maxLen = -1;

        for(int i=0; i<s.length(); i++)
        {
            if(!mp.empty() && mp.find(s[i]) != mp.end())
            {   
                int len = i - (mp[s[i]] + 1);
                if(maxLen < len){
                    maxLen = len;
                }
            }
            else{
                mp[s[i]] = i;
            }
        }

        return maxLen;
    }
};
