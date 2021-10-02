#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool bfs(map<int, vector<int>> &adj, int color[], int u) {

    queue<int> q;
    q.push(u);
    int col = 1;
    color[u] = col;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(auto x:adj[node]) {
            if(color[x]==-1) {
                color[x] = 1 - color[node];
                q.push(x);
            } else{
                if(color[x] == color[node]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

bool bipartite(map<int,vector<int>> &adj, int n) {
    int color[n+1];
    memset(color, -1, sizeof(color));
    for(auto x:adj) {
        if(color[x.first]==-1) {
            if(!bfs(adj, color, x.first)) {
               return 0; 
            }
        }
    }
    return 1;
}

int main() {

    

    map<int, vector<int>> adj;

    int n, e;
    cin>>n>>e;
    for(int i = 0; i < e; ++i) {
        ll x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if(bipartite(adj, n)) {
        cout<<"Bipartite"<<endl;
    } else{
        cout<<"Not Bipartite"<<endl;
    }
    
    return 0;
}