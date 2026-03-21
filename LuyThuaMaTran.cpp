// Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên
// cho trước. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 10^9+7.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
int n, k;
ll a[11][11], b[11][11];

void nhan_ma_tran(ll x[11][11], ll y[11][11]){
    ll z[11][11];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            z[i][j] = 0;
            for (int k = 0; k < n; k++){
                z[i][j] += x[i][k] * y[k][j];
                z[i][j] %= mod;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            x[i][j] = z[i][j];
        }
    }
}

void luythua(ll x[11][11], int k){
    if (k == 1) return;
    else{
        luythua(x, k / 2);
        nhan_ma_tran(x, x);
        if (k % 2 != 0) nhan_ma_tran(x, b);
    }
}

int main(){
    int test;
    cin >> test;
    while (test--){
        cin >> n >> k;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }

        luythua(a, k);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}