#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
vector<int> adj[1001];
vector<bool> visited;

void bfs(int u){
	queue<int> qu;
	qu.push(u);
	visited[u] = true;
	while (!qu.empty()){
		int s = qu.front();
		qu.pop();
		for (int v : adj[s]){
			if (visited[v] == false){
				qu.push(v);
				visited[v] = true;
			}
		}
	}
}

int dem_tplt(){
	int tplt = 0;
	for (int i = 1; i <= n; i++){
		if (visited[i] == false){
			tplt += 1;
			bfs(i);
		}
	}
	return tplt;
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

int main(){
	cin >> n;
	visited.assign(n + 1, false);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	dothi();
	cout << dem_tplt();
	return 0;
}