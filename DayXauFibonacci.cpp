// Day xau Fibonacci
// g1 = g2 = 1
// gi = gi-2 + gi-1

#include <bits/stdc++.h>
using namespace std;

char find_Gi(int n, long long I, vector<long long> &len){
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (I <= len[n - 2]){   // neu vi tri can tim nho hon gi-2 thi co nghia la vi tri do nam trong xau gi-2
        return find_Gi(n - 2, I, len);  // do dai xau - vi tri can tim - mang chua xau
    }
    else{  // nguoc lai
        return find_Gi(n - 1, I - len[n - 2], len);  // I - len[n-2] vi: gi = gi-2 + gi-1 => gi-1 = gi - gi-2
    }
}

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        long long I;
        cin >> n >> I;

        vector<long long> len(94);
        len[1] = len[2] = 1;    // len 2 xau goc
        for (int i = 3; i <= 93; i++){
            len[i] = len[i - 1] + len[i - 2];
        }
        
        cout << find_Gi(n, I, len) << endl;
    }
    return 0;
}