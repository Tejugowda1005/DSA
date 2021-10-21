class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int res = 0, i, j, n = g.size(), m = s.size();
        i=j=0;
        
        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                ++i; ++j;
                ++res;
            } else{
                ++j;
            }
        }
        return res;
    }
};