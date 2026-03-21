// Xâu AB đặc biệt: In ra các xâu AB độ dài N có DUY NHẤT 1 xâu con có K kí tự liên tiếp

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<char> res(20);
vector<char> c = { 'A', 'B' };
vector<vector<char>> ans;

bool check() {
    int dem = 0;
    // sliding window
    for (int i = 0; i <= n - k; i++) {
        bool ok = true;
        for (int j = 0; j < k; j++) {
            if (res[i + j] != 'A') { // xét trong xâu con
                ok = false;
                break;
            }
        }
        if (ok) dem++;
    }
    return dem == 1;
}

void Try(int i) {
    for (int j = 0; j < 2; j++) {
        res[i] = c[j];
        if (i == n) {
            if (check()) ans.push_back(res);
            return;
        }
        else Try(i + 1);
    }
}

int main() {
    cin >> n >> k;
    res.resize(n);

    Try(0);

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        for (char c : ans[i]) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}