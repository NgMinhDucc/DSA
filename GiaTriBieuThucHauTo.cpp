// Tinh gia tri bieu thuc hau to
// VD: 875*+9- = 34

#include <bits/stdc++.h>
using namespace std;

void CalSuffix(string s) {
    stack<int> st;
    for (int i = 0; i < int(s.length()); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int temp;
            
            if (s[i] == '+') temp = b + a;
            if (s[i] == '-') temp = b - a;
            if (s[i] == '*') temp = b * a;
            if (s[i] == '/') temp = b / a;
            if (s[i] == '%') temp = b % a;
            if (s[i] == '^') temp = int(pow(b, a));
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
        CalSuffix(s);
    }
    return 0;
}