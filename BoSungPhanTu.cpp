// BO SUNG PHAN TU: Cho mang A gom n phan tu. Dem so phan tu con thieu trong mang.

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test;
	cin >> test;
	while (test--){
		int n;
		cin >> n;
		int a[n];
		set<int> save;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			save.insert(a[i]); // loai bo phan tu trung nhau
		}
		vector<int> b(save.begin(), save.end());
		int dem = (b.back() - b.front() + 1) - b.size(); // cong thuc dem so phan tu con thieu trong day
		cout << dem << endl;
	}
	return 0;
}
