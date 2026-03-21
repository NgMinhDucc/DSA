#include <bits/stdc++.h>
using namespace std;

class Convert{
    public:
    string PostfixToInfix(string s){
        stack<string> st;
        for (int i = 0; i < int(s.length()); i++){
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                string fi = st.top(); st.pop();
                string se = st.top(); st.pop();
                string temp = "(" + se + s[i] + fi + ")";
                st.push(temp);
            }
            else st.push(string(1, s[i]));
        }
        return st.top();
    }
};

int main(){
    int test;
    cin >> test;
    Convert cv;
    while (test--){
        string s;
        cin >> s;
        cout << cv.PostfixToInfix(s) << endl;
    }
    return 0;
}