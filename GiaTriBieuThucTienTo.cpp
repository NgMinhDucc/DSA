// Tinh gia tri bieu thuc tien to
// VD: -+8/632 = 8

#include <bits/stdc++.h>
using namespace std;

void CalPrefix(string s) {
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int temp;

            if (s[i] == '+') temp = a + b;
            if (s[i] == '-') temp = a - b;
            if (s[i] == '*') temp = a * b;
            if (s[i] == '/') temp = a / b;
            if (s[i] == '%') temp = a % b;
            if (s[i] == '^') temp = int(pow(a, b));
            st.push(temp);
        }
        else st.push(s[i] - '0');
    }
    cout << st.top() << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        CalPrefix(s);
    }
    return 0;
}