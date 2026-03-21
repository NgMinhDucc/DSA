// LIET KE XAU NHI PHAN: Liet ke cac xau nhi phan tu 1 den n

#include <bits/stdc++.h>
using namespace std;

vector<string> res;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        queue<string> q;
        q.push("1");
        res.push_back("1");
        while (res.size() < 10000){
            string top = q.front();
            q.pop();
            res.push_back(top + "0");
            res.push_back(top + "1");
            q.push(top + "0");
            q.push(top + "1");
        }
        for (int i = 0; i < n; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}