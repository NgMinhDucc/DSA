// TIM CHI SO NHO NHAT: Cho day A gom n phan tu, vi tri s va so k
// Tim vi tri t nho nhat sao cho: A[t] + A[t + 1] + ... + A[s] <= k
// Ap dung Prefix sum

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n, s;
        long long k;
        cin >> n >> s >> k;
        vector<long long> prefix(n);
        vector<int> a(n);
        cin >> a[0];
        prefix[0] = a[0];
        for (int i = 1; i < n; i++){
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }
        long long sum = prefix[s - 1];
        int t = 0;
        while (sum > k){
            sum -= a[t];
            t++;
        }
        if (t >= s) cout << -1 << endl;
        else cout << t + 1 << endl;
    }
    return 0;
}