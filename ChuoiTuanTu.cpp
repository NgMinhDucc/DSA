#include <bits/stdc++.h>
using namespace std;

void MaHoa(string s){
    int i = 0;
    while (i < s.length()){
        char c = s[i];
        int count = 1;
        while (i + 1 < s.length() && s[i + 1] == c){
            count++;
            i++;
        }
        cout << count << c;
        i++;
    }
    cout << endl;
}

void solve(){
    int test;
    cin >> test;
    while (test--){
        string str;
        cin >> str;
        MaHoa(str);
    }
}

int main(){
    solve();
    return 0;
}