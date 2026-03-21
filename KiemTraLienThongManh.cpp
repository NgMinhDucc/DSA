#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<int> adj[1001];
vector<bool> visited;
vector<int> path;

void dfs(int u){
    path.push_back(u);
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}
    
string check(){
    for (int i = 1; i <= n; i++){
        visited.assign(n + 1, false);
        path.clear();
        dfs(i);
        if (path.size() != n){ // tu 1 dinh co the di qua tat ca cac dinh khac
            return "not strongly connected";
        }
    }
    return "strongly connected";
}

void dothi(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1){
                adj[i].push_back(j);
                // adj[j].push_back(i);
            }
        }
    }
}

int main(){
    cin >> n;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    dothi(); // chuyen sang danh sach ke
    cout << check();
    return 0;
}