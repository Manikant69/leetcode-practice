class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row = 0, res = 0;
        int lastCnt = 0;

        while(row < bank.size())
        {

            int cntDevices = 0;

            for(int j=0; j<bank[row].size(); j++)
            {
                if(bank[row][j] == '1'){
                    cntDevices++;
                }
            }

            res = res + (lastCnt * cntDevices);
            if(cntDevices != 0){
                lastCnt = cntDevices;
            }

            row++;
        }

        return res;
    }
};
