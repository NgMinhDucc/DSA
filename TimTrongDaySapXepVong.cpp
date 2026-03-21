// Tim kiem trong day sap xep vong.

#include <bits/stdc++.h>
using namespace std;

int timkiem(int n, int x, vector<int>& a){
    int l = 0, r = n - 1;
    while (l <= r){
        int m = (l + r) / 2;
        if (x == a[m]) return m + 1;
        if (a[l] <= a[m]){ // Kiem tra nua trai co tang khong
        // Chia doi day con
            if (x >= a[l] && x < a[m]){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        else{ // Kiem tra nua phai co tang khong
        // Chia doi day con
            if (x > a[m] && x <= a[r]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << timkiem(n, x, a) << endl;
    }
    return 0;
}