#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b){
    long long boi = (a / gcd(a, b)) * b;
    return boi;
}

void solve(){
}

int main(){
    solve();
    return 0;
}