// DEM SO BUOC TOI THIEU: Cho day A gom n phan tu. Sap xep lai day theo thu tu tang dan
// Dieu kien: Chi duoc chon 1 so o 1 vi tri bat ki va chuyen no len dau day hoac xuong cuoi day
// Dem so buoc toi thieu de co 1 xau tang dan

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    int MAX = 1, cur = 1;
    for (int i = 2; i <= n; i++){
        if (pos[i] > pos[i - 1]){
            cur++;
            MAX = max(MAX, cur);
        }
        else{
            cur = 1;
        }
    }
    cout << n - MAX;
    return 0;
}