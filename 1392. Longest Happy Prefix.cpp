class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        int pre = 0, suff = 1;
        vector<int> lps(n, 0);//longest prefix suffix array


        while(suff < n)
        {
            //matched
            if(s[suff] == s[pre]){
                lps[suff] = pre + 1;
                pre++;
                suff++;
            }
            //not matched
            else{

                if(pre == 0){
                    lps[suff] = 0;
                    suff++;
                }
                else{
                    pre = lps[pre - 1];
                }
            }
        }

        // string ans = "";

        // for(int i=0; i<lps[n-1]; i++)
        // {
        //     ans += s[i];
        // }
        // return ans;

        
        return s.substr(0, lps[n-1]);
    }
};
