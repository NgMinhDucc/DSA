#include <bits/stdc++.h>
using namespace std;

int n, u;
vector<vector<int>> a(1001, vector<int>(1001));
vector<int> x(1001);
vector<bool> visited;

void GhiNhan(){
    for (int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void ham(int pos, int cur){
    if (pos == n){
        if (a[cur][u - 1] != 0){
            x[pos] = cur + 1; // cuoi - dau
            GhiNhan();
        }
        return;
    }
    for (int i = 0; i < n; i++){
        if (a[cur][i] != 0 && !visited[i]){
            visited[i] = true;
            x[pos] = i + 1;
            ham(pos + 1, i);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> u;
    x[0] = u;
    visited.assign(n, false);
    visited[u - 1] = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    ham(1, u - 1);
    return 0;
}