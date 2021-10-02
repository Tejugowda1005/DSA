class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj, int color[], int col, int u) {
        color[u] = col;
        bool res = 1;
        for(auto x:adj[u]) {
            if(color[x]==-1) {
                res = res & dfs(adj, color, 1-col, x);
            } else{
                if(color[x]==color[u]) {
                    res =0;
                    break;
                }
            }
        }
        return res;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        memset(color, -1, sizeof(color));
        
        for(int i = 0;i < n; ++i) {
            if(color[i]==-1 && dfs(graph, color, 0, i) == false){
                return 0;
            }
        }
        return 1;
    }
};