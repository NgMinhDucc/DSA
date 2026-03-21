#include <bits/stdc++.h>
using namespace std;

int n, m, start;
vector<int> a[1001];
vector<bool> visited;

void DFS(int u){
	cout << u << " ";
	visited[u] = true; // danh dau la da tham
	// tham tat ca cac dinh ke
	for (int v : a[u]){
		if (!visited[v]){ // neu chua tham thi goi lai ham
			DFS(v);
		}
	}
}

int main(){
	int test;
	cin >> test;
	while (test--){
		cin >> n >> m >> start; // so dinh va so canh
		for (int i = 1; i <= n; i++){
			a[i].clear();
		}
		visited.assign(n + 1, false); // reset ve false cho case sau
		for (int i = 1; i <= m; i++){
			int x, y;
			cin >> x >> y; // dinh va cac dinh ke cua no
			a[x].push_back(y);
			a[y].push_back(x);
		}
		DFS(start); // truyen vao dinh nao thi thuat toan se bat dau tu dinh do (dinh truyen vao <= n)
		cout << endl;
	}
	return 0;
}
