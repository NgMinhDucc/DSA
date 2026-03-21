// Tim day con lien tuc co tong lon nhat
// VD:
// -2 -5 6 -2 -3 1 5 -6
// Co day 6 -2 -3 1 5 co tong lon nhat day la 7
// Goi y: Day con lien tuc co the nam het ben trai, hoac ben phai, hoac o giua

#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(int a[], int l, int m, int r){
    int sum = 0;
    int left_sum = -1e9, right_sum = -1e9;

    // tinh tong ben trai
    for (int i = m; i >= l; i--){
        sum += a[i];
        if (sum > left_sum){
            left_sum = sum;
        }
    }
    sum = 0;

    // tinh tong ben phai
    for (int i = m + 1; i <= r; i++){
        sum += a[i];
        if (sum > right_sum){
            right_sum = sum;
        }
    }
    sum = 0;

    // tinh tong o giua
    return left_sum + right_sum;
}

int maxSubArraySum(int a[], int l, int r){
    if (l == r) return a[l];
    int m = (l + r) / 2;
    return max({maxSubArraySum(a, l, m), maxSubArraySum(a, m + 1, r), maxCrossingSum(a, l, m, r)});
}

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        cout << maxSubArraySum(a, 0, n - 1) << endl;
    }
    return 0;
}