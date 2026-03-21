#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> a[1001];
vector<bool> visited;
vector<int> parent;

void dfs(int u){
	visited[u] = true;
	for (int v: a[u]){
		if (!visited[v]){
			parent[v] = u; // ghi nhan u la bo cua v (*)
			dfs(v);
		}
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int i : a[v]){
			if (!visited[i]){
				q.push(i);
				visited[i]= true;
				parent[i] = v; // ghi nhan v la bo cua i
			}
		}
	}
}

void path(int start, int end){
//	dfs(start);
	bfs(start);
	if (!visited[end]){ // truong hop ko co duong di giua 2 dinh 
		cout << "-1\n";
	}
	else{
		// truy vet duong di
		vector<int> d; // luu cac dinh ma thuat toan di qua
		// bat dau tu dinh end
		while (end != start){
			d.push_back(end);
			// chung nao end con != start thi tiep tuc lan nguoc lai
			end = parent[end];
		}
		d.push_back(start); // day not dinh start vao vi truoc day ta dang di nguoc tu end len
		reverse(d.begin(), d.end());
		for (int i : d){
			cout << i << " ";
		}
		cout << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--){
		cin >> n >> m >> s >> t;
		for (int i = 1; i <= n; i++){
			a[i].clear();
		}
		visited.assign(n + 1, false);
		parent.assign(n + 1, 0);
		for (int i = 1; i <= m; i++){
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		path(s, t);
	}
	return 0;
}
