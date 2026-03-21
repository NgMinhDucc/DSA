// Đếm cặp: Đếm số cặp phần tử có hiệu nhỏ hơn K trong mảng A gồm N phần tử 

#include <bits/stdc++.h>
using namespace std;

long long Count(long long n, long long k, vector<long long>& a){
    long long dem = 0;
    for (long long i = 0; i < n; i++){
        long long st = k + a[i];
        // công thức tính số cặp phần tử a[j] < a[i] + k và j > i:
        dem += lower_bound(a.begin() + i + 1, a.end(), st) - (a.begin() + i + 1);
    }
    return dem;
}

int main(){
    long long test;
    cin >> test;
    while (test--){
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end()); // sort vì lower_bound và upper_bound chỉ trả kết quả đúng nếu hàm đã được sort

        cout << Count(n, k, a) << endl;
    }
    return 0;
}