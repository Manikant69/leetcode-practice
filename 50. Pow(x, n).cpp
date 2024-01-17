class Solution {
public:
    double myPow(double x, int nn) 
    {
        double ans = 1.0;
        bool pow_neg = nn < 0;

        long n = abs(nn);

        while(n>0)
        {
            if(n%2==1)
            {
                ans *= x;
                n--;
            }
            else
            {
                x *= x;
                n = n/2;
            }
        }
        if(pow_neg)
            return  1/ans;

        return ans;
    }
};
