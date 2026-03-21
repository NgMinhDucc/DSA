// Hoan vi ke tiep: Sinh ra hoan vi tiep theo cua hoan vi da cho

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];

void next_per(int n, int a[]){
	int i = n - 1;
	while (i >= 1 && a[i] >= a[i + 1]){
		i--;
	}
	if (i == 0){
		for (int j = 1; j <= n; j++){
			a[j] = j;
			cout << a[j] << " ";
		}
		cout << endl;
	}
	else{
		int j = n;
		while (a[j] < a[i]){
			j--;
		}
		swap(a[i], a[j]);
		int l = i + 1, r = n;
		while (l < r){
			swap(a[l], a[r]);
			l++; r--;
		}
		for (int x = 1; x <= n; x++){
			cout << a[x] << " ";
		}
		cout << endl;
	}
}

int main(){
	int test;
	cin >> test;
	while (test--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		next_per(n, a);
	}
	return 0;
}
