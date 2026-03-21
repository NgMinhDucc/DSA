// Cho so N. Goi R la so dao cua N. Tinh luy thua R cua N.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod= 1e9 + 7;

ll luy_thua_dao(ll a, ll b){
    if (b == 0) return 1;
    else{
        ll x = luy_thua_dao(a, b / 2);
        if (b % 2 == 0){
            return (x * x) % mod;
        }
        else{
            return (a * ((x * x) % mod)) % mod;
        }
    }
}

int main(){
    int test;
    cin >> test;
    while (test--){
        ll n;
        cin >> n;
        ll temp = n;
        ll rev = 0;
        while (n != 0){
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        cout << luy_thua_dao(temp, rev) << endl;
    }
    return 0;
}