#include <bits/stdc++.h>
using namespace std;

void Valid(stack<char> st, string s){
    for (char c : s){
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else{
            if (st.empty()){
                cout << "NO\n";
                return;
            }
            else{
                if ((c == ')' && st.top() == '(') || 
                    (c == ']' && st.top() == '[') ||
                    (c == '}' && st.top() == '{'))
                    st.pop();
            }
        }
    }
    if (st.empty()) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int test;
    cin >> test;
    while (test--){
        string s;
        cin >> s;
        stack<char> st;
        Valid(st, s);
    }
    return 0;
}