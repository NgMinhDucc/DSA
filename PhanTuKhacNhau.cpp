// Cho 2 mang da duoc sep xep: A co N phan tu va B co N-1 phan tu. A va B co duy nhat 1 phan tu khac nhau. Tim vi tri phan tu do.

#include <bits/stdc++.h>
using namespace std;

int pos(int n, int m, long long a[], long long b[]){
    int i = 0, j = 0;
    while (j < m){
        if (a[i] != b[j]){
            return i + 1;
        }
        i++, j++;
    }
    return n + 1;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        int m = n - 1;
        long long a[n], b[m];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int j = 0; j < m; j++){
            cin >> b[j];
        }

        cout << pos(n, m, a, b) << endl;
    }
    return 0;
}