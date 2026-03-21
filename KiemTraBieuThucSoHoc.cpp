// Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?
// Có nâng cao thêm chút với [] và {}

#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
    stack<char> st;
    for (int i = 0; i < int(s.length()); i++) {
        if (s[i] != ')' && s[i] != ']' && s[i] != '}') {
            st.push(s[i]);
        }
        else {
            bool coToanTu = false;
            while (!st.empty() && st.top() != '(' && st.top() != '[' && st.top() != '{') {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    coToanTu = true;
                }
                st.pop();
            }
            if (!st.empty()) st.pop(); // xoa dau mo ngoac
            if (!coToanTu) return true; // neu khong co toan tu nao giua () or [] or {} thi nghia la co ngoac thua
        }
    }
    return false; // khong co ngoac thua
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        if (solve(s)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}