// Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n. 
// VD: n = 5
// Ta có 5 = 1 + 1 + 1 + 1 + 1
// Với mỗi dấu "+", ta có 2 lựa chọn: hoặc cộng vào hoặc giữ nguyên
// mà giữa 2 số luôn có 1 dấu "+"
// nên ta có 2^(5-1) = 2^4 = 16 dấu "+" tất cả, tương ứng với 16 dãy số có tổng các phần tử = 5
// TỔNG QUÁT: Cho 1 số nguyên dương n, tách số đó ra thành tổng của các số 1 -> có n-1 dấu "+", tương ứng 2^(n-1) dãy số có tổng các phần tử = n

#include <bits/stdc++.h>
using namespace std;

const int mod = 123456789;

long long composition(long long n, long long k){
    if (k == 0) return 1;
    else{
        long long x = composition(n, k / 2);
        if (k % 2 == 0){
            return (x * x) % mod;
        }
        else{
            return (n * ((x * x) % mod)) % mod;
        }
    }
}

int main(){
    int test;
    cin >> test;
    while (test--){
        long long n;
        cin >> n;

        cout << composition(2, n - 1) << endl;
    }
    return 0;
}

// 3 = 1 + 1 + 1
// 2^2 = 4