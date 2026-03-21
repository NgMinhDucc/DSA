// Giao cua 3 day so: Tim phan tu xuat hien o ca 3 mang cho truoc
// Neu mang chua duoc sort san thi nho sort roi hang lam

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n, m, p;
        cin >> n >> m >> p;
        vector<long long> a(n), b(m), c(p);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int j = 0; j < m; j++){
            cin >> b[j];
        }
        for (int k = 0; k < p; k++){
            cin >> c[k];
        }

        vector<long long> ans;
        int x = 0, y = 0, z = 0;
        while (x < n && y < m && z < p){
            if (a[x] == b[y] && b[y] == c[z]){
                ans.push_back(a[x]);
                x++; y++; z++;
            }
            else{
                long long MIN = min({a[x], b[y], c[z]});
                if (a[x] == MIN) x++;
                if (b[y] == MIN) y++;
                if (c[z] == MIN) z++;
            }
        }

        if ((int)ans.size() == 0) cout << -1 << endl;
        else{
            for (long long it : ans){
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}