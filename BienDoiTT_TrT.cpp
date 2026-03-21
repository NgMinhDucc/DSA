// Bien doi tien to - trung to (prefix - infix)
// VD: *+AB-CD -> ((A+B)*(C-D))

#include <bits/stdc++.h>
using namespace std;

void tiento_trungto(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string temp = "(" + fi + s[i] + se + ")";
            st.push(temp);
        }
        else st.push(string(1, s[i]));
    }
    cout << st.top() << endl;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        tiento_trungto(s);
    }
    return 0;
}