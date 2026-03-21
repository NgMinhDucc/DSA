// Bộ 3 số có tổng nhỏ hơn K: Đếm số bộ 3 số có tổng nhỏ hơn K trong mảng A gồm N phần tử.
// Dùng binary_search nếu chỉ cần kiểm tra có tồn tại hay không
// Dùng lower/upper_bound nếu cần đếm số bộ

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Count(ll n, ll k, vector<ll>& a) {
    ll dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll sh = k - a[i] - a[j];
            auto it = lower_bound(a.begin() + j + 1, a.end(), sh) - (a.begin() + j + 1);
            dem += it;
        }
    }
    cout << dem << endl;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        Count(n, k, a);
    }
    return 0;
}