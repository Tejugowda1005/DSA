class Solution {
public:
    
    bool dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &recSt, vector<int> &safe, int i) {
        vis[i] = recSt[i] = 1;
        
        for(auto x:graph[i]) {
            if(!vis[x] && dfs(graph, vis, recSt,safe, x)) {
                safe[x]=0;
                return 1;
            } else if(vis[x] && recSt[x]) {
                safe[x]=0;
                return 1;
            }
        }
        recSt[i] = 0;
        return 0;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safe(n, 1);
        
        vector<int> vis(n, 0), recStack(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i] && dfs(graph, vis, recStack,safe, i)) {
                safe[i]=0;
            }
        }
        
        vector<int> res;
        
        for(int i = 0; i < n; ++i) {
            if(safe[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};