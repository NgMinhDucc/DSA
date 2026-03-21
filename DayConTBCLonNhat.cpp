// DAY CON CO TRUNG BINH CONG LON NHAT

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int MAX = *max_element(a.begin(), a.end());
    int max_len = 0, cur_len = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == MAX){
            cur_len++;
            max_len = max(max_len, cur_len);
        }
        else cur_len = 0;
    }
    cout << max_len;
    return 0;
}