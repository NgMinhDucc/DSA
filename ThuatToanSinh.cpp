// IN RA CAC XAU NHI PHAN THUAN NGHICH

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> res(101, 0);

bool palindrome(int n, vector<int> &a){
    for (int i = 1; i <= n / 2; i++){
        if (a[i] != a[n - i + 1]){ // do bat dau tu chi so 1 nen thay vi danh chi so n - i - 1, chung ta danh n - i + 1
            return false;
        }
    }
    return true;
}


void in(){
    if (palindrome(n, res)){ // truyen n vao ham vi day moi la kich thuoc mang hop le, khong phai n + 1
        for (int i = 1; i <= n; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

void Try(int k){
    for (int i = 0; i <= 1; i++){
        res[k] = i;
        if (k == n){
            in();
        }
        else{
            Try(k + 1);
        }
    }
}

int main(){
    cin >> n;
    res.resize(n + 1);
    Try(1);
    return 0;
}