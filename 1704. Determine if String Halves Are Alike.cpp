class Solution {
private:
    bool isVowel(char ch)
    {
        //converting character into upparcase
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - 32;
        }

        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true;
        }

        return false;
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int cnt1 = 0, cnt2 = 0;

        int i = 0 , j = n/2;

        while(j<n)
        {
            if(isVowel(s[i])){
                cnt1++;
            }

            if(isVowel(s[j])){
                cnt2++;
            }
            i++; 
            j++;
        }

        return cnt1 == cnt2;

    }
};
