// Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’, còn lại là phụ âm.
// Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <= c <= ‘H’) sao cho mỗi chữ cái được sử
// dụng đúng một lần và xâu kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm.
// Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

#include <bits/stdc++.h>
using namespace std;

char c;
vector<char> a;
vector<char> b;
vector<bool> used;

bool NguyenAm(char x) {
    return (x == 'A' || x == 'E');
}

bool check() {
    int n = a.size();
    for (int i = 1; i < n - 1; i++) {
        if (!NguyenAm(a[i - 1]) && NguyenAm(a[i]) && !NguyenAm(a[i + 1])) return false;
    }
    return true;
}

void in() {
    if (check()) {
        for (char x : a) cout << x;
        cout << endl;
    }
}

void Try(int i) {
    for (int j = 0; j < (int)b.size(); j++) {
        if (!used[j]) {
            a[i] = b[j];
            used[j] = true;
            if (i == (int)b.size() - 1) in();
            else Try(i + 1);
            used[j] = false;
        }
    }
}

int main() {
    cin >> c;
    for (char i = 'A'; i <= c; i++) {
        b.push_back(i);
    }
    sort(b.begin(), b.end());
    int n = b.size();
    a.resize(n);
    used.assign(n, false);
    Try(0);
    return 0;
}