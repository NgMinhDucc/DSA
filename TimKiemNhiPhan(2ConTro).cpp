// TIM KIEM NHI PHAN: Tim so K trong mang kich thuoc N. Neu tim duoc thi in ra vi tri tuong ung trong mang, khong thi in ra "NO"
// Dung 2 con tro code se chay nhanh hon 1 chut

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool mark = true;
        int l = 0, r = n - 1; // 2 con tro, 1 con tuong ung chi so dau, 1 con tuong ung chi so cuoi
        while (l <= r){
            if (a[l] == k){
                cout << l + 1 << endl;
                mark = false;
                break;
            }
            else{
                l++;
            }
            if (a[r] == k){
                cout << r + 1 << endl;
                mark = false;
                break;
            }
            else{
                r--;
            }
        }
        if (mark){
            cout << "NO\n";
        }
    }
    return 0;
}