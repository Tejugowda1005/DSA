class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        map<int, int> coin;
        for(int i = 0; i < n; ++i) {
            if(bills[i]==5) {
                ++coin[5];
            }
            else if(bills[i]==10) {
                if(coin[5]>0) {
                    --coin[5];
                    ++coin[10];
                } else{
                    return 0;
                }
            }
            else {
                if(coin[5] > 0 && coin[10] > 0) {
                    --coin[5];
                    --coin[10];
                    ++coin[20];
                } else if(coin[5] >= 3) {
                    coin[5] -= 3;
                    ++coin[20];
                } 
                else{
                    return 0;
                }
            }
        }
        return 1;
    }
};