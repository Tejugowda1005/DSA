class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        memset(color, -1, sizeof(color));
        
        for(int i = 0; i < n; ++i) {
            
            if(color[i]==-1) {
                
                queue<int> q;
                q.push(i);
                color[i] = 0;
                
                while(!q.empty()) {
                    
                    int node = q.front();
                    q.pop();
                    
                    for(auto x:graph[node]) {
                        if(color[x]==-1) {
                            color[x] = 1-color[node];
                            q.push(x);
                        }
                        else if(color[x]==color[node]) {
                            return 0;
                        }
                    }   
                }
            }
        }
        return 1;
    }
};