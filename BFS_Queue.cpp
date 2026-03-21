#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<int> adj[1001];
vector<bool> visited(1001);

void bfs(int u){
	queue<int> qu;
	qu.push(u);
	visited[u] = true;
	while (!qu.empty()){
		int v = qu.front();
		qu.pop();
		cout << v << " ";
		for (int t : adj[v]){
			if (!visited[t]){
				qu.push(t);
				visited[t] = true;
			}
		}
	}
}

void dtvh(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1 and i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

// void dtch(){
//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= n; j++){
//             if (a[i][j] == 1){
//                 adj[i].push_back(j);
//             }
//         }
//     }
// }

int main(){
    cin >> n;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    
    dtvh();
    // dtch();
	   bfs(1);
    return 0;
}