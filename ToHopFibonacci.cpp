// SINH RA CA TO HOP CHAP K CUA N, CAC PHAN TU TRONG TO HOP CO TONG LA 1 SO FIBONACCI

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, k;
vector<int> res(101, 0);
vector<ll> fibo(93);
vector<ll> save;

void fibonacci(){
    fibo[0] = 0;
    save.push_back(fibo[0]);
    fibo[1] = 1;
    save.push_back(fibo[1]);
    for (int i = 2; i <= 92; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        save.push_back(fibo[i]);
    }
}

void in(){
    int tong = 0;
    for (int i = 1; i <= k; i++){
        tong += res[i];
    }
    for (int i = 0; i < save.size(); i++){
        if (tong == save[i]){
            for (int i = 1; i <= k; i++){
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
}

// j: x[i - 1] + 1
// j: n - k + i
void Try(int i){
    for (int j = res[i - 1] + 1; j <= n - k + i; j++){
        res[i] = j;
        if (i == k){
            in();
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    cin >> n >> k;
    res.resize(k + 1);
    fibonacci();
    Try(1);
    return 0;
}