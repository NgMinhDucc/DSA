// Tap con ke tiep: Sinh ra to hop ke tiep tu to hop cho truoc

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1001];

void next_com(int n, int k, int a[]){
	int i = k;
	while (i >= 1 && a[i] == n - k + i){
		i--;
	}
	if (i == 0){
		for (int j = 1; j <= k; j++){
			a[j] = j;
		}
		for (int x = 1; x <= k; x++){
			cout << a[x] << " ";
		}
		cout << endl;
	}
	else{
		a[i]++;
		for (int j = i; j <= k; j++){
			a[j + 1] = a[j] + 1;
		}
		for (int x = 1; x <= k; x++){
			cout << a[x] << " ";
		}
		cout << endl;
	}
}

int main(){
	int test;
	cin >> test;
	while (test--){
		cin >> n >> k;
		for (int i = 1; i <= k; i++){
			cin >> a[i];
		}
		
		next_com(n, k, a);
	}
	return 0;
}
