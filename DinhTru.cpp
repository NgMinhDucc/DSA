#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<int> adj[1001];
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int dem_tplt(){
    int so_tplt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
            so_tplt += 1;
        }
    }
    return so_tplt;
}

void dinh_tru(){
    int tplt = dem_tplt();
    for (int i = 1; i <= n; i++){
        visited.assign(n + 1, false);
        visited[i] = true;
        int cnt = 0;
        for (int j = 1; j <= n; j++){
            if (!visited[j]){
                cnt += 1;
                dfs(j);
            }
        }
        if (cnt > tplt){
            cout << i << " ";
        }
    }
}

void dothi(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1){
                adj[i].push_back(j);
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
    dothi();
    dinh_tru();
    return 0;
}