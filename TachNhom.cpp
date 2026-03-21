// CO THE TACH A RA THANH IT NHAT BAP NHIEU NHOM SAO CHO MOI SO TRONG NHOM DEU CO THE TIM DUOC IT NHAT 1 SO CUNG NHOM CO CHENH LECH <= K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int dem = 0;
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && a[j] - a[j - 1] <= k) {
            j++;
        }
        dem++;
        i = j;
    }
    cout << dem;
    return 0;
}