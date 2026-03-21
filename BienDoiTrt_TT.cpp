#include <bits/stdc++.h>
using namespace std;

class Convert{
    public:
    string InfixToPrefix(string s){
        string res;
        stack<char> st;
        for (int i = s.length() - 1; i >= 0; i--){
            if (s[i]>= 'A' && s[i] <= 'Z') res += s[i];
            if (s[i] >= 'a' && s[i] <= 'z') res += s[i];
            if (s[i] == ')') st.push(s[i]);
            if (s[i] == '('){
                while (!st.empty() && st.top() != ')'){
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
                while (!st.empty() && pri(st.top()) >= pri(s[i])){
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty()){
            if (st.top() != ')'){
                res += st.top();
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    private:
    int pri(char c){
        if (c == '^') return 10000;
        if (c == '*' || c == '/') return 1000;
        if (c == '+' || c == '-') return 100;
        else return 10;
    }
};

int main(){
    int test;
    cin >> test;
    while (test--){
        string s;
        cin >> s;
        Convert cv;
        cout << cv.InfixToPrefix(s) << endl;
    }
    return 0;
}