#include <bits/stdc++.h>
using namespace std;

int n, u;
int cnt = 1;
vector<vector<int>> a(1001, vector<int>(1001));
vector<int> adj[1001];
vector<bool> visited;

bool degree(){
    for (int i = 1; i <= n; i++){
        int deg = 0;
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1){
                deg++;
            }
        }
        if (deg % 2 != 0){
            return false;
        }
    }
    return true;
}

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
            cnt++;
        }
    }
}

void dothi(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1 && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

bool connected(){
    dfs(u);
    return cnt == n;
}

int check(vector<vector<int>> &ar, int t){
    int d = 0;
    for (int i = 1; i <= n; i++){
        if (ar[t][i] != 0){
            d = i;
            break;
        }
    }
    return d;
}

void euler(int u){
    stack<int> st;
    st.push(u);
    vector<int> ce;
    while (!st.empty()){
        int s = st.top();
        int canhke = check(a, s);
        if (canhke != 0){
            st.push(canhke);
            a[canhke][s] = 0;
            a[s][canhke] = 0;
        }
        else{
            st.pop();
            ce.push_back(s);
        }
    }
    reverse(ce.begin(), ce.end());
    for (int i : ce){
        cout << i << " ";
    }
}

int main(){
    cin >> n >> u;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    dothi();
    if (!degree() || !connected()){
        cout << "no Euler cycle";
    }
    else{
        euler(u);
    }
    return 0;
}