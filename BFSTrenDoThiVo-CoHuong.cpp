// BFS: Breath First Search: Thuat toan tim kiem theo CHIEU RONG

#include <bits/stdc++.h>
using namespace std;

int n, m, start;
vector<bool> visited;
vector<int> a[1001];

void BFS(int u){
	queue<int> q;
	q.push(u); // day dinh dau tien vao queue
	visited[u] = true; // danh dau la da tham 
	while (!q.empty()){
		int v = q.front(); // lay dinh dau tien hien tai trong queue
		q.pop();
		cout << v << " ";
		for (int i : a[v]){ // tham cac dinh ke cua dinh hien tai
			if (!visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(){
	int test;
	cin >> test;
	while (test--){
		cin >> n >> m >> start;
		for (int i = 1; i <= n; i++){
			a[i].clear();
		}
		visited.assign(n + 1, false);
		for (int i = 1; i <= m; i++){
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x); // bo di neu do thi CO HUONG
		}
		BFS(start); // truyen vao dinh nao thi thuat toan se bat dau tu dinh do
		cout << endl;
	}
	return 0;
}
