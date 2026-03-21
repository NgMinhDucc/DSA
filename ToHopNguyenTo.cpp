//  SINH RA CAC TO HOP CHAP K CUA N, CAC PHAN TU TRONG TO HOP CO TONG LA 1 SO NGUYEN TO

#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> res;
const int MAX = 1e6;
vector<bool> prime(MAX + 1, true);

void sieve(){
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= MAX; i++){
		if (prime[i]){
			for (int j = i * i; j <= MAX; j += i){
				prime[j] = false;
			}
		}
	}
}

void in(){
	int tong = 0;
	for (int i = 1; i <= k; i++){
		tong += res[i];
	}
	if (prime[tong]){
		for (int i = 1; i <= k; i++){
			cout << res[i] << " ";
		}
		cout << endl;
	}
}

void Try(int i){
	for (int j = res[i - 1] + 1; j <= n - k + i; j++){
		res[i] = j;
		if (i == k){
			in();
		}
		else{
			Try(i + 1);
		}
	}
}

int main(){
	sieve();
	cin >> n >> k;
	res.resize(k + 1);
	res[0] = 0;
	Try(1);
	return 0;
}