// Bộ 3 số có tổng bằng K: Kiểm tra trong mảng A gồm N phần tử có bộ 3 số sao cho Ai + Aj + Ak = K không
// Dùng binary_search nếu chỉ cần kiểm tra có tồn tại hay không
// Dùng lower/upper_bound nếu cần đếm số bộ

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int bi_search(ll n, ll sh, ll left, vector<ll>& a) {
    int l = left, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (sh == a[m]) return 1;
        else {
            if (sh > a[m]) l = m + 1;
            if (sh < a[m]) r = m - 1;
        }
    }
    return 0;
}

void Count(ll n, ll k, vector<ll>& a) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll sh = k - a[i] - a[j];
            if (bi_search(n, sh, j + 1, a) == 1) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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