// Sinh xau nhi phan bang thuat toan sinh

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a(11);
int ok = 1;

// khoi tao cau hinh dau: 000...0
void ktao(){
	for (int i = 1; i <= n; i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n;
	while (i >= 1 && a[i] == 1){ // lien tuc duyet tu phai-trai cho toi khi bit hien tai != 1
		a[i] = 0; // doi cac bit 1 thanh bit 0
		i--;
	}
	if (i == 0) ok = 0; // cau hinh cuoi: 111...1
	else a[i] = 1; // neu gap bit 0 thi doi thanh bit 1
}

int main(){
	cin >> n;
	ktao();
	while (ok){
		for (int i = 1; i <= n; i++){
			cout << a[i];
		}
		cout << endl;
		sinh();
	}
	return 0;
}
