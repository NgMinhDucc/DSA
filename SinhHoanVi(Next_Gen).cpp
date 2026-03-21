// Sinh hoan vi tu 1...n bang thuat toan sinh

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a(11);
int ok = 1;

// khoi tao cau hinh dau: 1 2 ... n
void ktao(){
	for (int i = 1; i <= n; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = n - 1;
	while (i >= 1 && a[i] >= a[i + 1]){ // lien tuc duyet tu phai-trai cho toi khi a[i] < a[i + 1]
		i--;
	}
	if (i == 0) ok = 0; // cau hinh cuoi: n n-1 ... 1
	else{ // neu chua phai cau hinh cuoi
		int j = n;
		while (a[i] > a[j]){ // tim phan tu lon hon be nhat so voi phan tu hien tai
			j--;
		}
		swap(a[i], a[j]);
		int l = i + 1, r = n;
		while (l < r){ // dao lai day con tinh tu sau phan tu hien tai
			swap(a[l], a[r]);
			l++, r--;
		}
	}
}

int main(){
	cin >> n;
	ktao();
	while (ok){
		for (int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		sinh();
	}
	return 0;
}
