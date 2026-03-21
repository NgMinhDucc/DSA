// Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:
// Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.
// Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].
// Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu.

#include <bits/stdc++.h>
using namespace std;

// Do phần tử chính giữa của mỗi lần biến đổi đều có index = 2^n
// nên ta lưu các index đó vào mảng
long long a[55];
void pre_calculate(){
    a[1] = 1;
    for (int i = 2; i <= 55; i++){
        a[i] = a[i - 1] * 2;
    }
}
// a = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, ...]

int main(){
    pre_calculate();
    
    int test;
    cin >> test;
    while (test--){
        int n;
        long long k;
        cin >> n >> k;

        for (int i = n; i >= 1; i--){
            if (k > a[i]){
                k -= a[i];
            }
            else if (k == a[i]){
                cout << i << endl;
                break;
            }
            else{
                continue;
            }
        }
    }
    return 0;
}