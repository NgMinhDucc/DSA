// HAON VI KE TIEP: In ra hoan vi ke tiep cua day so vua nhap

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++){
            cin >> num[i];
        }
        if (next_permutation(num.begin(), num.end())){
            // tu dong sinh ra hoan vi tiep theo
            for (int i = 0; i < n; i++){
                cout << num[i] << " ";
            }
            cout << endl;
        }
        else{
            // neu day so vua nhap la hoan vi cuoi, ham tu dong quay hoan vi ban dau
            for (int i = 0; i < n; i++){
                cout << num[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}