// VOI MOI SO X TRONG [L,R], TIM TSNT LON NHAT CUA X VA TINH TONG CUA CHUNG

#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	cin >> test;
	while (test--){
		int l, r;
		cin >> l >> r;
		vector<int> prime(r + 1, 1);
		prime[0] = prime[1] = 0;
		for (int i = 2; i <= r; i++){
			if (prime[i] == 1){
				for (int j = i; j <= r; j += i){
					prime[j] = i;
				}
			}
		}
		int tong = 0;
		for (int i = l; i <= r; i++){
			tong += prime[i];
		}
		cout << tong << endl;
	}
	return 0;
}