// Bai toan cai tui (Knapsack Problem)
// Mot nguoi co cai tui the tich V (V<1000). Anh ta co N do vat can mang theo (N=1000), moi do vat co the tich la A[i] (A[i]=100) va
// gia tri la C[i] (C[i]=100). Hay xac dinh tong gia tri lon nhat cua cac do vat ma nguoi do co the mang theo, sao cho tong the tich
// khong vuot qua V.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, v;
vector<int> a(1005), c(1005);
ll weight = 0, cost = 0, fopt = 0;

// cap nhat gia tri tot nhat
void update(){
	if (cost > fopt){
		fopt = cost;
	}
}

// tinh can tren
double cal_upper(int i){
	double upper = cost;
	ll remain = v - weight;
	while (i <= n && remain >= a[i]){
		upper += c[i];
		remain -= a[i];
		i++;
	}
	
	if (i <= n){
		upper += 1.0 * remain * c[i] / a[i];
	}
	return upper;
}

void Try(int i){
	if (i > n){
		update();
		return;
	}
	
	ll up = cal_upper(i);
	if (up <= fopt){
		return;
	}
	
	if (weight + a[i] <= v){
		// nhanh con
		weight += a[i];
		cost += c[i];
		Try(i + 1);
		
		// quay lui
		weight -= a[i];
		cost -= c[i];
	}
	// nhanh khong con
	Try(i + 1);
}

// sap xep giam dan theo ti le c/a
void sort_by_ratio(){
	vector<pair<double, int>> ratio;
	for (int i = 1; i <= n; i++){
		ratio.push_back({1.0 * c[i] / a[i], i});
	}
	sort(ratio.begin(), ratio.end(), greater<>());
	
	vector<int> A(1005), C(1005);
	for (int i = 0; i < n; i++){
		A[i + 1] = a[ratio[i].second];
		C[i + 1] = c[ratio[i].second];
	}
	
	for (int i = 1; i <= n; i++){
		a[i] = A[i];
		c[i] = C[i];
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> v;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			cin >> c[i];
		}
		
		sort_by_ratio();
		Try(1);
		
		cout << fopt << endl;
		weight = cost = fopt = 0;
	}
	return 0;
}