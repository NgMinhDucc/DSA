#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool mark = false;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (x == a[m]) {
                cout << m + 1 << endl;
                mark = true;
                break;
            }
            else {
                if (x > a[m]) {
                    l = m + 1;
                }
                else if (x < a[m]) {
                    r = m - 1;
                }
            }
        }
        if (!mark) cout << "NO\n";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, x;
// int a[11];

// int bi_search(int l, int r){
//     int m;
//     if (l > r) return 0;
//     else{
//         m = (l + r) / 2;
//         if (x == a[m]) return 1;
//         else if (x > a[m]){
//             return bi_search(m + 1, r);
//         }
//         else{
//             return bi_search(l, m - 1);
//         }
//     }
// }

// int main(){
//     cin >> n >> x;
//     for (int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     sort(a, a + n);
//     if (bi_search(0, n - 1)) cout << "YES";
//     else cout << "NO";
//     return 0;   
// }