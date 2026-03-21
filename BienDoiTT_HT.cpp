// Bien doi tien to - hau to (prefix - suffix)
// VD: *+AB-CD -> AB+CD-*

#include <bits/stdc++.h>
using namespace std;

void tiento_hauto(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string temp = fi + se + s[i];
            st.push(temp);
        }
        else st.push(string(1, s[i]));
    }
    cout << st.top() << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        tiento_hauto(s);
    }
    return 0;
}