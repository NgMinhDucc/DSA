// SO BDN 1: In ra cac xau nhi phan <= N (BDN: Binary Digit Number)

#include <bits/stdc++.h>
using namespace std;

bool sosanh(string a, string b){
    if (a.length() != b.length()){
        return a.length() < b.length(); // tra ve so ngan hon
    }
    return a <= b; // neu 2 so bang nhau thi so sanh gia tri
}

void BDN(string n, queue<string> q){
    q.push("1");
    int dem = 0;
    while (!q.empty()){ // (*)
        string cur = q.front();
        q.pop();
        if (sosanh(cur, n)){
            dem++;
        }
        string next1 = cur + "0", next2 = cur + "1";
        // chi day vao nhung so <= n
        if (sosanh(next1, n)){
            q.push(next1);
        }
        if (sosanh(next2, n)){
            q.push(next2);
        }
    }
    cout << dem << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--){
        string n;
        cin >> n;
        queue<string> q;
        BDN(n, q);
    }
    return 0;
}