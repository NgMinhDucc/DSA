// DAY CON TONG = K: Dua ra cac day con cua day A co tong = k

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a(10), res(10);
bool mark; // bien danh dau

void in(int x){ // kich thuoc cac day con ko co dinh
    cout << "[";
    for (int i = 0; i < x; i++){
        if (i < x - 1){
            cout << res[i] << " ";
        }
        else{
            cout << res[i] << "] ";
        }
    }
}

void QuayLui(int i, int cur, int tong){
    if (tong == k){
        in(i);
        mark = true; // danh dau da tim dc day con
        return;
    }
    else{
        for (int j = cur; j < n; j++){
            tong += a[j]; // cong phan tu thu j vao tong
            res[i] = a[j]; // luu phan tu do vao res
            if (tong <= k){
                QuayLui(i + 1, j + 1, tong); // neu tong chua bang k thi goi lai ham
            }
            tong -= a[j]; // quay lui de tim phan tu phu hop neu tong hien tai vuot qua K
        }
    }
}

int main(){
    int test;
    cin >> test;
    while (test--){
        cin >> n >> k;
        mark = false;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.begin() + n);
        QuayLui(0, 0, 0);
        if (!mark){
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}