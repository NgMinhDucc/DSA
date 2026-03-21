// Cho mảng A[] gồm n phần tử. Hãy tìm dãy con liên tục của mảng A[R], .., A[L] sao cho khi sắp xếp lại dãy con ta nhận được một
// mảng được sắp xếp. Ví dụ với A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60} ta chỉ cần sắp xếp lại dãy con từ A[4],.., A[9]: {30,
// 25, 40, 32, 31, 35} để có mảng được sắp.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end()); // a sau khi sap xep
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++){
            if (b[i] - a[i] != 0){
                p.push_back({a[i], i});
            }
        }
        cout << p[0].second + 1 << " " << p[p.size() - 1].second + 1 << endl;
    }
    return 0;
}