class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length()-1;
        
        while(i < j)
        {
            while((i < j-1) && s[i] == s[i+1] && s[i] == s[j]){
                i++;
            }

            while((j > i+1) && s[j] == s[j - 1] && s[j] == s[i])
            {
                j--;
            }
            
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else
            {
                break;
            }
        }

        if(i != j)
            return j - i + 1;
        return 1;
    }
};
