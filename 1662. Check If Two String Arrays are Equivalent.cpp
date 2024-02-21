class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int i = 0, j = 0;
        int ch1 = 0, ch2 = 0;

        while(i < word1.size() && j < word2.size())
        {
            if(word1[i][ch1] != word2[j][ch2]){
                return false;
            }
            ch1++;
            ch2++;

            if(ch1 >= word1[i].length()){
                i++;
                ch1 = 0;
            }
            if(ch2 >= word2[j].length()){
                j++;
                ch2 = 0;
            }
        }

        return (i == word1.size() && j == word2.size());
    }
};
