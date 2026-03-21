#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

long long tohop(int n, int k){
    if (k == 0 || n == k){
        return 1;
    }
    else{
        return (tohop(n - 1, k - 1) + tohop(n - 1, k));
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    cout << tohop(n, k);
}

int main(){
    solve();
    return 0;
}