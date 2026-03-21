// So lan quay vong: Ban dau day A gom N phan tu duoc sap xep tang dan
// Cho 1 cau hinh sau khi da quay vong phai K vong. Tim so K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int idx = -1;
        for (int i = 0; i < n - 1; i++){
            if (a[i] > a[i + 1]){
                idx = i + 1;
                break;
            }
        }

        if (idx == -1) cout << 0 << endl;
        else cout << idx << endl;
    }
    return 0;
}

// k = 0 => 1 2 3 4 5
// k = 1 => 5 1 2 3 4
// k = 2 => 4 5 1 2 3
// k = 3 => 3 4 5 1 2