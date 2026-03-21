#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

long long dem(long long n){
    if (n < 10){
        return 1;
    }
    else{
        return (n + dem(n / 10));
    }
}

void solve(){
    long long n;
    cin >> n;
    cout << dem(n);
}

int main(){
    solve();
    return 0;
}