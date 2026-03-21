// Thap Ha Noi

#include <bits/stdc++.h>
using namespace std;

void ThapHaNoi(int n, char a, char b, char c) {
    if (n == 1) { // chuyen dia lon nhat tu A sang C
        cout << a << " -> " << c << endl;
        return;
    }
    ThapHaNoi(n - 1, a, c, b); // chuyen n - 1 dia tu A sang B (C lam trung gian)
    cout << a << " -> " << c << endl;
    ThapHaNoi(n - 1, b, a, c); // chuyen n - 1 dia tu B sang C (A lm trung gian)
}

int main() {
    int n;
    cin >> n;
    ThapHaNoi(n, 'A', 'B', 'C');
    return 0;
}