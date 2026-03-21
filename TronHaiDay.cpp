// TRON HAI DAY: Cho mang A gom N phan tu va mang B gom M phan tu. 
// Hop nhat 2 mang thanh 1 mang da duoc sap xep

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int test;
	cin >> test;
	while (test--){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		int i = 0, j = 0;
		while (i < n && j < m){
			// so sanh phan tu nao be hon thi in truoc, sau do tang index va tiep tuc so sanh
			if (a[i] <= b[j]){
				cout << a[i] << " ";
				i++;
			}
			else{
				cout << b[j] << " ";
				j++;
			}
		}
		// neu day nao con phan tu chua duoc in thi in not
		while(i < n){
			cout << a[i++] << " ";
		}
		while (j < m){
			cout << b[j++] << " ";
		}
		cout << endl;
	}
}
