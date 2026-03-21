// Day con tong bang S

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--){
        int n, s;
        cin >> n >> s;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        vector<bool> dp(s + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++){
            for (int j = s; j >= a[i]; j--){
                if (dp[j - a[i]]){
                    dp[j] = true;
                }
            }
        }
        if (dp[s]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}