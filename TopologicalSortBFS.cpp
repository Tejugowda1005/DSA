#include<bits/stdc++.h>
using namespace std;

/*

1) Maintain an array with name "indegree" and calculate indegrees for each nodes
2) Maintain a queue and push all nodes having indegree 0 into the queue
3) Now do bfs using that queue , the way elements will be popped out of queue is the topo sort for the graph


If it has multiple components do one thing, to get indegrees get those for each component and then find the Topo sort


6 5 0 1 2 3 4 
*/


bool dfs(map<int, vector<int>> &adj, map<int, bool> &vis, map<int, bool> &recStack, int i){

    vis[i] = 1;
    recStack[i] = 1;
    bool res = 0;
    for(auto x:adj[i]) {
        if(!vis[x]){
            res = res | dfs(adj, vis, recStack, x);
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
            if(dfs(adj,vis,recStack, i)){
                return 1;
            }
        }
    }
    return 0;
}




void getIndegree(map<int, vector<int>> &adj, map<int, int> &indegree, map<int, bool> &vis, int node){

    queue<int> q;
    indegree[node] = 0;
    q.push(node);

    while(!q.empty()) {

        node = q.front();
        q.pop();

        for(auto x:adj[node]) {
            ++indegree[x];
            if(!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
}

void TopologicalSortBFS(map<int, vector<int>> &adj, int n, vector<int> &TopoSort) {

    // 1) maintain indegrees for each nodes for every component;
    map<int, int> indegree;
    map<int, bool> vis;

    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            getIndegree(adj, indegree, vis, i);
        }
    }


    // TOPO SORT STARTS:

    // 2) Maintain a queue and push all nodes having indegree 0 into the queue

    queue<int> q;
    for(auto x:indegree) {
        if(x.second==0){
            q.push(x.first);
        }
    }
    

    //3) Now do bfs using that queue , the way elements will be popped out of queue is the topo sort for the graph

    // jaage ki bachat
    vis.clear();

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        TopoSort.push_back(node);

        for(auto x:adj[node]) {
            if(!vis[x]) {
                --indegree[x];
                vis[x] = 1;
                q.push(x);
            }
        }
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

    TopologicalSortBFS(adj, n, TopoSort);

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