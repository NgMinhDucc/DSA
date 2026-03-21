#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<int> adj[1001];
vector<bool> visited;
vector<pair<int, int>> canh;

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

void dfs2(int u, int s, int t){
    visited[u] = true;
    for (int v : adj[u]){
        if ((u == s && v == t) || (u == t  && v == s)){
            continue;
        }
        if (!visited[v]){
            dfs2(v, s, t);
        }
    }
}

void canhcau(){
    int tplt = dem_tplt();
    for (auto it : canh){
        int x = it.first, y = it.second;
        visited.assign(n + 1, false);
        int cnt = 0;
        for (int j = 1; j <= n; j++){
            if (!visited[j]){
                cnt += 1;
                dfs2(j, x, y);
            }
        }
        if (cnt > tplt){
            cout << x << " " << y << endl;
        }
    }
}

void dothi(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1 && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                canh.push_back({i, j});
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
    canhcau();
    return 0;
}