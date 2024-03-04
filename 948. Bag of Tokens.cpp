class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore = 0, score = 0;
        sort(tokens.begin(), tokens.end());

        int i = 0, j = tokens.size() - 1;

        while(i <= j)
        {
            if(tokens[i] <= power)
            {
                score++;
                power -= tokens[i];
                i++;
            }
            else if(score >= 1)
            {
                score--;
                power += tokens[j];
                j--;
            }
            else{
                break;
            }

            if(score > maxScore){
                maxScore = score;
            }
        }

        return maxScore;
    }
};
