// Cặp phần tử có tống = K: Đếm số cặp phần tử có tổng = K trong mảng A gồm N phần tử.
// Dùng binary_search nếu chỉ cần kiểm tra có tồn tại hay không
// Dùng lower/upper_bound nếu cần đếm số cặp

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Count(ll n, ll k, vector<ll>& a) {
    ll dem = 0;
    for (int i = 0; i < n; i++) {
        ll sh = k - a[i];
        dem += upper_bound(a.begin() + i + 1, a.end(), sh) - lower_bound(a.begin() + i + 1, a.end(), sh); // '>' - '>=' = '='
    }
    return dem;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        cout << Count(n, k, a) << endl;
    }
    return 0;
}