// LUY THUA: Tinh n^k modulo 1e9 + 7
//http://oj.28tech.com.vn/martor/413ac24e-8af4-445b-bfd0-a88c59a68fd0.png -> cong thuc tinh

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

ll luythua(ll n, ll k){
    if (k == 0) return 1;
    ll lt = luythua(n, k / 2);
    if (k % 2 == 0) return (lt % MOD * lt % MOD) % MOD;
    else return ((lt % MOD * lt % MOD) % MOD) * n % MOD;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        ll n, k;
        cin >> n >> k;
        cout << luythua(n, k) << endl;
    }
    return 0;
}