// CAC SO TRONG MANG DEU XUAT HIEN VOI TAN SUAT CHAN, CHI CO DUY NHAT 1 SO XUAT HIEN VOI TAN SUAT LE. IN RA SO DO

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> check(100000); // khai bao kich thuoc mang danh dau dua tren so n
        for (int i = 0; i < n; i++){
            cin >> a[i];
            check[a[i]]++;
        }
        for (int i = 0; i < n; i++){
            if (check[a[i]] % 2 != 0){
                cout << a[i];
            }
            check[a[i]] = 0;
        }
        cout << endl;
    }
    return 0;
}