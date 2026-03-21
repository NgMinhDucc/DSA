// Cho mang da duoc sap xep A gom N phan tu va so X. Tra ve phan tu lon nhat trong A nho hon hoac bang X.

#include <bits/stdc++.h>
using namespace std;

int Floor(int n, int x, long long a[]){
    if (x < a[0] || x > a[n - 1]){
        return -1;
    }
    for (int i = 0; i < n; i++){
        if (a[i] > x){
            return i;
        }
    }
    return -1;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        int n, x;
        cin >> n >> x;
        long long a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        cout << Floor(n, x, a) << endl;
    }
    return 0;
}