// Tinh so Fibonacci thu N
// Cong thuc: {{1, 1}, {1, 0}} ^ n = {{F(n+1), F(n)}, {F(n), F(n-1)}}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

void nhan_ma_tran(ll a[2][2], ll b[2][2]){
    // nhan 2 ma tran voi nhau
    ll x = (((a[0][0] % mod) * (b[0][0] % mod)) + ((a[0][1] % mod) * (b[1][0] % mod))) % mod;
    ll y = (((a[0][0] % mod) * (b[0][1] % mod)) + ((a[0][1] % mod) * (b[1][1] % mod))) % mod;
    ll z = (((a[1][0] % mod) * (b[0][0] % mod)) + ((a[1][1] % mod) * (b[1][0] % mod))) % mod;
    ll t = (((a[1][0] % mod) * (b[0][1] % mod)) + ((a[1][1] % mod) * (b[1][1] % mod))) % mod;

    // gan gia tri moi cho a
    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = t;
}

void luythua(ll a[2][2], int n){
    if (n == 1) return;

    ll b[2][2] = {{1, 1}, {1, 0}};
    luythua(a, n / 2);
    nhan_ma_tran(a, a);
    if (n % 2 != 0){
        nhan_ma_tran(a, b);
    }
}

ll fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    ll a[2][2] = {{1, 1}, {1, 0}};
    luythua(a, n);
    return a[0][1];
}

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        cout << fib(n) << endl;
    }
    return 0;
}