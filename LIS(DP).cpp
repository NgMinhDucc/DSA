// LIS: Longest Increasing Subsequence - Day con tang dai nhat
// In ra do dai cua day con tang dai nhat tim duoc trong mang A gom N phan tu

#include <bits/stdc++.h>
using namespace std;

void LIS(int n, vector<int>& a){
	vector<int> le(n, 1); // mang luu do dai cua cac day con tang
	// kiem tra cac phan tu hien tai co > cac phan tu truoc do khong
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			if (a[i] > a[j]){
				le[i] = max(le[i], le[j] + 1); // tang do dai day con tai phan tu thu i (tuc co the them phan tu do vao day con)
			}
		}
	}
	cout << *max_element(le.begin(), le.end());
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	LIS(n, a);
	return 0;
}