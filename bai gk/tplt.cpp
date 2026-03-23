#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<int> adj[1001];
vector<bool> visited;
vector<int> tmp;
vector<vector<int>> res;

void dfs(int u){
    tmp.clear();
    stack<int> st;
    tmp.push_back(u);
    st.push(u);
    visited[u] = true;
    while (!st.empty()){
        int s = st.top();
        st.pop();
        for (int v : adj[s]){
            if (!visited[v]){
                tmp.push_back(v);
                visited[v] = true;
                st.push(s);
                st.push(v);
                break;
            }
        }
    }
    res.push_back(tmp);
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

void tplt(){
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
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
    tplt();
    for (int i = 0; i < int(res.size()); i++){
        cout << "Thanh phan lien thong " << i + 1 << endl;
        for (int j : res[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}