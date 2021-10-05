class Solution {
public:
    
    void dfsTopo(map<int, vector<int>> &adj, stack<int> &resStack, map<int, bool> &vis, int node) {
        
        vis[node] = 1;
        for(auto x:adj[node]) {
            if(!vis[x]){
                dfsTopo(adj, resStack, vis, x);
            }
        }
        resStack.push(node);
    }
    
    
    
    bool dfs(map<int, vector<int>> &adj, map<int, bool> &recStack, map<int, bool> &vis, int node) {
        
        recStack[node] = vis[node] = 1;
        bool res = 0;
        for(auto x:adj[node]) {
            if(!vis[x]){
                res = res | dfs(adj, recStack, vis, x);
            } else if(recStack[x]){
                res = 1;
                break;
            }
        }
        recStack[node] = 0;
        return res;
    }
    
    bool detectCycle(map<int, vector<int>> &adj, int n) {
        map<int, bool> vis, recStack;
        
        for(int i = 0; i <n; ++i) {
            if(!vis[i] && dfs(adj, recStack, vis, i)) {
                return 1;
            }
        }
        return 0;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int prlen = prerequisites.size();
        for(int i = 0; i < prlen; ++i){
            swap(prerequisites[i][0], prerequisites[i][1]);
        }
        
        map<int, vector<int>> adj;
        
        
        for(int i = 0; i < prlen; ++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        
        
        vector<int> res;
        
        if(detectCycle(adj, numCourses)) {
            return res;
        }
        
        map<int, bool> vis;
        stack<int> resStack;
        
        for(int i = 0; i < numCourses; ++i){
            if(!vis[i]) {
                dfsTopo(adj, resStack, vis, i);
            }
        }
        
        while(!resStack.empty()) {
            res.push_back(resStack.top());
            resStack.pop();
        }
        
        return res;
    }
};