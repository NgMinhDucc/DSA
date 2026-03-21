#include <bits/stdc++.h>
using namespace std;

// su dung index de tinh do dai
// Li do: Can biet vi tri bat dau va ket thuc cua xau hop le. Do dai = dau - cuoi + 1
void Longest(stack<int> st, string s){
    st.push(-1);
    int len = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(') st.push(i);
        else{
            st.pop(); // neu gap dau ')' thi xoa phan tu o dinh stack
            if (st.empty()) st.push(i); // neu stack rong thi day index hien tai vao lam base moi
            else len = max(len, i - st.top()); // tinh do dai tu dinh stack toi index hien tai
        }
    }
    cout << len << endl;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        string s;
        cin >> s;
        stack<int> st;
        Longest(st, s);
    }
    return 0;
}

