#include <bits/stdc++.h>
using namespace std;

void Solution(){
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s){
        if (c == '(') st.push(c);
        else{
            if (st.empty()){
                cout << "invalid\n";
                return;
            }
            else st.pop();
        }
    }
    if (st.empty()) cout << "valid\n";
    else cout << "invalid\n";
}

void Test(){
    int test;
    cin >> test;
    while (test--){
        Solution();
    }
}

int main(){
    Test();
    // Solution();
    return 0;
}