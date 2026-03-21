// Sinh to hop chap k cua n bang thuat toan sinh

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a(11);
int ok = 1;

// khoi tai cau hinh dau: 1 2 ... k
void ktao(){
	for (int i = 1; i <= k; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while (i >= 1 && a[i] == n - k + i){ // lien tuc duyet tu phai-trai cho toi khi gap dc phan tu da dat max tai vi tri cua no
		i--;
	}
	if (i == 0) ok = 0; // cau hinh cuoi: n-k+1 n-k+2 ... n (n-k+k)
	else{ // neu chua phai cau hinh cuoi
		a[i]++; // tang phan tu do len 1 don vi
		for (int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1; // bien doi day con sau phan tu do thanh day tang dan
		}
	}
}

int main(){
	cin >> n >> k;
	ktao();
	while (ok){
		for (int i = 1; i <= k; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		sinh();
	}
	return 0;
}
