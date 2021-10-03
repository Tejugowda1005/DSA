class Solution {
public:
    void dfs(map<int, vector<int>> &adj, vector<int> &incoming, map<int, bool> &vis, vector<int> &res, int node) {
        
        res.push_back(node);
        for(auto x:adj[node]) {
            
            if(!vis[x]){
                if(--incoming[x] > 0) {
                    continue;
                }
                
                vis[x] = 1;
                dfs(adj, incoming, vis, res, x);
            }
        }
        
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int prlen = prerequisites.size();
        for(int i = 0; i < prlen; ++i){
            swap(prerequisites[i][0], prerequisites[i][1]);
        }
        
        map<int, vector<int>> adj;
        
        vector<int> incoming(numCourses);
        
        for(int i = 0; i < prlen; ++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            ++incoming[prerequisites[i][1]];
        }
        
        
        vector<int> res;
        map<int, bool> vis;
        
        int lastSize = -1;
        
        for(int i = 0; i < numCourses; ++i){
            if(!vis[i] && incoming[i]==0) {
                vis[i] = 1;
                dfs(adj, incoming, vis, res, i);
            }
            
            if(i==numCourses-1 && res.size() < numCourses) {
                if(lastSize==res.size()) {
                    return {};
                }
                lastSize = res.size();
                i=0; 
            }
        }
        return res;
    }
};