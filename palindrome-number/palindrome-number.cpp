class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        vector<int> tmp;
        while(x > 0 ){
            tmp.push_back(x%10);
            x/=10;
        }
        vector<int> tmp2 = tmp;
        reverse(tmp.begin(), tmp.end());
        
        return tmp==tmp2;
    }
};