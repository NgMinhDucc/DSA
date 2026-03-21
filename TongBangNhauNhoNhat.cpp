// Cho dãy số nguyên dương A[] có N phần tử. Người ta cố gắng chia dãy A[] thành các đoạn liên tiếp sao tổng của các đoạn đó bằng nhau.
// Ví dụ: dãy A[] = {2, 5, 1, 3, 3, 7} có thể được chia thành 3 đoạn {2, 5} {1, 3, 3} {7} cùng có tổng các phần tử bằng 7.
// Hãy tính giá trị tổng liên tiếp nhỏ nhất có thể của các đoạn con tổng bằng nhau trong dãy A.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i];
    }
    vector<int> u;
    for (int i = 1; i * i <= tong; i++) {
        if (tong % i == 0) {
            u.push_back(i);
            if (i != (tong / i)) {
                u.push_back(tong / i);
            }
        }
    }
    sort(u.begin(), u.end());
    for (int i = 0; i < u.size(); i++) {
        int tong_con = 0;
        bool mark = true;
        for (int j = 0; j < n; j++) {
            tong_con += a[j];
            if (tong_con > u[i]) {
                mark = false;
                break;
            }
            if (tong_con == u[i]) {
                tong_con = 0;
            }
        }
        if (mark && tong_con == 0) {
            cout << u[i] << endl;
            return;
        }
    }
    cout << tong << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}