class Solution {
public:
    bool closeStrings(string word1, string word2) {
       vector<int> w1Freq(26, 0), w2Freq(26, 0);
       
       set<char> st1 , st2;

       for(auto ch : word1)
       {
           w1Freq[ch - 'a']++;
           st1.insert(ch);
       }

       for(auto ch : word2)
       {
           w2Freq[ch - 'a']++;
           st2.insert(ch);
       }

        //sort the freq
        sort(w1Freq.begin(), w1Freq.end());
        sort(w2Freq.begin(), w2Freq.end());

        //to check all characters in both the string are same 
        //also check that the frequency of any characters are same. 
        return (st1 == st2 && w1Freq == w2Freq);
    }
};
