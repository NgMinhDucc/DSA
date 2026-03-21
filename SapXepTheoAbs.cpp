// SAP XEP THEO GIA TRI TUYET DOI: Cho mang A gom N phan tu va so X.
// Sap xep cac phan tu cua A theo gttd |X - A[i]|

#include <bits/stdc++.h>
using namespace std;

int x; // khai bao toan cuc truy cap cho de

bool cmp(int a, int b){
	return abs(x - a) < abs(x - b);
}

int main(){
	int test;
	cin >> test;
	while (test--){
		int n;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		stable_sort(a.begin(), a.end(), cmp); // giu nguyen thu tu nhap cua cac phan tu trong mang (*)
		for (int i : a){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
