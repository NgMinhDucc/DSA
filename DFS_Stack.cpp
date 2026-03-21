#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<int> adj[1001];
vector<bool> visited(1001);

void dfs(int u){
	stack<int> st;
	st.push(u);
	cout << u << " ";
	visited[u] = true;
	while (!st.empty()){
		int s = st.top();
		st.pop();
		for (int v : adj[s]){
			if (!visited[v]){
				cout << v << " ";
				visited[v] = true;
				st.push(s);
				st.push(v);
				break;
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
// 	for (int i = 1; i <= n; i++){
// 		for (int j = 1; j <= n; j++){
// 			if (a[i][j] == 1){
// 				adj[i].push_back(j);
// 			}
// 		}
// 	}
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
	dfs(1);
	return 0;
}