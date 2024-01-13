class Solution {
public:
    int minSteps(string s, string t) {
        int cntChar[26] = {0};

        for(int i=0; i<s.length(); i++)
        {
            cntChar[s[i] - 'a']++;
            cntChar[t[i] - 'a']--;
        }

        int cnt = 0;
        
        for(int i=0; i<26; i++)
        {
            if(cntChar[i] > 0)
            {
                cnt += cntChar[i];
            }
        }

        return cnt;
    }
};
