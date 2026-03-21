// SAP XEP THEO SO LAN XUAT HIEN: Cho mang A gom n phan tu. Sap xep cac phan tu theo so lan xuat hien giam dan cua chung
// Neu 2 so co so lan xuat hien bang nhau thi in so nho hon truoc

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second;
} // comparator theo yeu cau dau bai

void Solution(){
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]]++; // tang so lan xuat hien theo tung phan tu nhap vao
	}
	vector<pair<int, int>> ve(mp.begin(), mp.end());
	sort(ve.begin(), ve.end(), cmp);
	for (auto it : ve){
		for (int i = 1; i <= it.second; i++){
			cout << it.first << " ";
		}
	}
	cout << endl;
}

void Test(){
	int test;
	cin >> test;
	while (test--){
		Solution();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Test();
//	Solution();
	return 0;
}
