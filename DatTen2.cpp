// DAT TEN 2: In ra cac to hop chap k cua n, cac phan tu la cac chu cai tu A den Z

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<char> letter(26);
vector<char> res(100);

void in(){
    for (int i = 0; i < k; i++){
        cout << res[i];
    }
    cout << endl;
}

void QuayLui(int i, int start){ // chon chu cai bat dau tu start, tuc la khong phai bat dau tu dau ma duyet tang dan
    for (int j = start; j < n; j++){
        res[i] = letter[j];
        if (i == k - 1){
            in();
        }
        else{
            QuayLui(i + 1, j + 1);
        }
    }
}

int main(){
    int test;
    cin >> test;
    int s = 0;
    for (int i = 65; i <= 90; i++){
        letter[s] = i;
        s++;
    }
    while (test--){
        cin >> n >> k;
        res.resize(k);
        QuayLui(0, 0);
    }
    return 0;
}