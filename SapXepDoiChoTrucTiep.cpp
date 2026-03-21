// SAP XEP DOI CHO TRUC TIEP: Doi cho ngay khi gap phan tu sau lon hon phan tu truoc

#include <bits/stdc++.h>
using namespace std;

void Solution(){
	int n, step = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[i]){
				swap(a[i], a[j]); // doi cho luon
			}
		}
		step++;
		cout << "Buoc " << step << ": ";
		for (int i : a){
			cout << i << " ";
		}
		cout << endl;
	}
}

//void Test(){
//	int test;
//	cin >> test;
//	while (test--){
//		Solution();
//	}
//}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//	Test();
	Solution();
	return 0;
}
