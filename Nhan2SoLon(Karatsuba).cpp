// Cho 2 so lon A va B. Tinh A*B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll karatsuba(ll x, ll y){
    if (x < 10 || y < 10) return x * y;
    else{
        ll len = max(to_string(x).length(), to_string(y).length());
        ll so_mu = len / 2;

        ll a = x / (ll)pow(10, so_mu);
        ll b = x % (ll)pow(10, so_mu);
        ll c = y / (ll)pow(10, so_mu);
        ll d = y % (ll)pow(10, so_mu);

        ll ac = karatsuba(a, c);
        ll bd = karatsuba(b, d);
        ll ad_bc = karatsuba(a + b, c + d) - ac - bd;
        
        return ac * (ll)pow(10, len) + ad_bc * (ll)pow(10, so_mu) + bd;
    }
}

int main(){
    int test;
    cin >> test;
    while (test--){
        ll n, m;
        cin >> n >> m;
        
        // can tinh x^y = n^m
        cout << karatsuba(n, m) << endl;
    }
    return 0;
}