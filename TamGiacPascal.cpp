// NHAP VAO SO NGUYEN N, IN RA TAM GIAC PASCAL VOI N DONG

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> pascal(n, 0);
    pascal[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << pascal[j] << " ";
        }
        cout << endl;
        for (int j = i + 1; j > 0; j--){
            pascal[j] += pascal[j - 1];
        }
    }
    return 0;
}