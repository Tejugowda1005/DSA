class Solution {
public:
    
    bool dfs(map<int, vector<int>> &adj, map<int, bool> &vis, map<int, bool> &recStack, int node) {
        vis[node] = recStack[node] = 1;
        bool res = 0;
        for(auto x:adj[node]) {
            if(!vis[x]) {
                res = res | dfs(adj, vis, recStack, x);
            } else if(recStack[x]) {
                res = 1;
                break;
            }
        }
        recStack[node] = 0;
        return res;
    }
    
    bool detectCycle(map<int, vector<int>> &adj, int n){
        map<int, bool> vis, recStack;
        
        for(int i = 0; i < n; ++i) {
            if(!vis[i] && dfs(adj, vis, recStack, i)) {
                return 1;
            }
        }
        return 0;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); ++i) {
            swap(prerequisites[i][0], prerequisites[i][1]);
        }
        
        map<int, vector<int>> adj;
        
        for(int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        
        return !detectCycle(adj, numCourses);
    }
};