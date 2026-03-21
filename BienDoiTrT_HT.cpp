// Bien doi trung to - hau to (infix - suffix)
// VD: (A+(B+C) -> ABC++

#include <bits/stdc++.h>
using namespace std;

// do uu tien giam dan cua cac toan tu
int priority(char c) {
    if (c == '^') return 5;
    if (c == '*' || c == '/') return 4;
    if (c == '+' || c == '-') return 3;
    return 2; // cac dau ngoac
}

void trungto_hauto(string s) {
    string ans = "";
    stack<char> st;
    for (int i = 0; i < int(s.length()); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') ans += s[i];
        if (s[i] >= 'a' && s[i] <= 'z') ans += s[i];
        if (s[i] == '(') st.push(s[i]);
        if (s[i] == ')') {
            while (st.size() != 0 && st.top() != '(') {
                ans += st.top(); // noi toan hang vao ans
                st.pop(); // xoa cho toi khi gap dau (
            }
            st.pop(); // xoa dau (
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            while (st.size() != 0 && priority(st.top()) >= priority(s[i])) {
                ans += st.top(); // noi toan tu co do uu tien cao hon vao ans
                st.pop(); // noi xong thi xoa
            }
            st.push(s[i]); // day toan tu co do uu tien nho hon vao stack
        }
    }

    // noi cac toan tu con lai vao ans
    while (st.size() != 0) {
        if (st.top() != '(') ans += st.top();
        st.pop();
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        trungto_hauto(s);
    }
    return 0;
}