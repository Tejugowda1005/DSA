#include<bits/stdc++.h>
using namespace std;

bool dfsCycle(map<int, vector<int>> &adj, map<int, bool> &vis, map<int, bool> &recStack, int i){

    vis[i] = 1;
    recStack[i] = 1;
    bool res = 0;
    for(auto x:adj[i]) {
        if(!vis[x]){
            res = res | dfsCycle(adj, vis, recStack, x);
        } else if(recStack[x]){
            res = 1;
            break;
        }
    }
    recStack[i]=0;
    return res;
}

bool cycleDetection(map<int, vector<int>> &adj, int n){
    map<int, bool> vis, recStack;
    for(int i = 0; i < n; ++i){
        if(!vis[i]) {
            if(dfsCycle(adj,vis,recStack, i)){
                return 1;
            }
        }
    }
    return 0;
}



void dfs(map<int, vector<int>> &adj, map<int, bool> &vis, int node, stack<int> &topSort) {

    vis[node] = 1;
    for(auto x:adj[node]) {
        if(!vis[x]) {
            dfs(adj, vis, x, topSort);
        }
    }

    topSort.push(node);
}

void TopologicalSortDFS(map<int, vector<int>> &adj, int n, vector<int> &res) {

    map<int, bool> vis;
    stack<int> topSort;
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            dfs(adj, vis, i, topSort);
        }
    }

    while(!topSort.empty()) {
        res.push_back(topSort.top());
        topSort.pop();
    }
}

void solve() {
    int n, e;
    cin>>n>>e;
    map<int,vector<int>> adj;
    for(int i = 0; i < e; ++i){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    if(cycleDetection(adj, n)) {
        cout<<"Cycle detected, so no topo sort"<<endl;
        return;
    }

    vector<int> TopoSort;

    TopologicalSortDFS(adj, n, TopoSort);

    for(auto x:TopoSort) {
        cout<<x<<' ';
    }
    
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("C:/Users/Lenovo/Desktop/inpOut/input.txt", "r", stdin); 
    freopen("C:/Users/Lenovo/Desktop/inpOut/output.txt", "w", stdout);
    freopen("C:/Users/Lenovo/Desktop/inpOut/error.txt", "w", stderr); 
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}