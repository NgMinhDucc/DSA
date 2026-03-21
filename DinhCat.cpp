// ARTICULATION POINT: Hãy liệt kê các đỉnh u theo thứ tự từ nhỏ đến lớn sao cho nếu bỏ u và các cạnh nối với u ra khỏi đổ thị thì đồ thị không còn liên thông nữa.

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj(1001); // adjacency list
vector<bool> visited(1001); // mang danh dau

void DFS(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            DFS(v);
        }
    }
}

int CC(){ // ConnectedComponet - dem so thanh phan lien thong
    int dem = 0;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dem++;
            DFS(i);
        }
    }
    return dem;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        cin >> n >> m;
        adj.assign(n + 1, {});
        for (int i = 0; i < m; i++){ // chuyen tu danh sach ke sang danh sach canh
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // do thi vo huong
        }

        // dem so diem cat (articulation point)
        int cc0 = CC(); // so luong thpt ban dau
        vector<int> dinhcat; // luu cac thlt ma neu bo di thi do thi khong con lien thong
        for (int u = 1; u <= n; u++){
            visited.assign(n + 1, false);
            visited[u] = true; // danh dau la da tham qua dinh thu i
            int cc1 = 0;
            for (int i = 1; i <= n; i++){
                if (!visited[i]){
                    cc1++; // dem so luong tplt sau khi bo di dinh u
                    DFS(i);
                }
            }
            if (cc1 > cc0){
                dinhcat.push_back(u);
            }
        }
        cout << dinhcat.size() << endl;
        for (int i : dinhcat){
            cout << i << " ";
        }
    }
    return 0;
}