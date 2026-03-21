// SO 0 VA SO 9: Cho so N. Hay tim so X nho nhat chi chua 2 so 0 va 9 chia het cho N

#include <bits/stdc++.h>
using namespace std;

vector<long long> res;

void Zero_Nine(int n, queue<string> q){
    q.push("9");
    res.push_back(9);
    while (res.size() < 901){ // vi n <= 100 nen x <= 900
        string top = q.front();
        q.pop();
        res.push_back(stoll(top + "0"));
        res.push_back(stoll(top + "9"));
        q.push(top + "0");
        q.push(top + "9");
    }
    for (int i = 0; i < 901; i++){
        if (res[i] % n == 0){
            cout << res[i] << endl;
            break;
        }
    }
    res.clear();
}

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        queue<string> q;
        Zero_Nine(n, q);
    }
    return 0;
}