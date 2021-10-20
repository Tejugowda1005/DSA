class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> deg;
        for(int i = 0; i < edges.size(); ++i) {
            deg[edges[i][1]]++;
            deg[edges[i][0]]++;
        }
        for(auto x:deg){
            if(x.second==edges.size())
                return x.first;
        }
        return -1;
    }
};