class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1, 0), outdeg(n+1, 0);
        int m = trust.size();
        for(int i = 0; i < m; ++i){
            indeg[trust[i][1]]++;
            outdeg[trust[i][0]]++;
        }
        for(int i = 1; i <= n; ++i) {
            if(indeg[i]==n-1 && outdeg[i]==0)
                return i;
        }
        return -1;
    }
};