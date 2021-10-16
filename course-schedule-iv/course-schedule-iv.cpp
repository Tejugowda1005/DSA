class Solution {
public:
    
    bool dfsUtil(vector<vector<int>> &adj, map<int, bool> &vis, int u, int v) {
        if(u==v) {
            return 1;
        }
        vis[u]=1;

        for(auto x:adj[u]){
            if(!vis[x] && dfsUtil(adj, vis, x, v)) {
                return 1;                
            }
        }
        return 0;
    }
    
    bool isReachable(vector<vector<int>> &adj, int u, int v) {
        map<int, bool> vis;
        return dfsUtil(adj, vis, u, v);
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = prerequisites.size();
        if(n==0){
            return vector<bool>(numCourses,0);
        }
        
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i < n; ++i) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        int q = queries.size();
        vector<bool> res(q, 0);
        for(int i = 0; i < q; ++i) {
            int u = queries[i][0], v = queries[i][1];
            
            res[i] = isReachable(adj, u, v);
        }
        
        return res;
    }
};