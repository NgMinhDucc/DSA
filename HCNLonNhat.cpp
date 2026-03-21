// Cho N cột, mỗi cột có chiều cao bằng H[i]. Bạn hãy tìm hình chữ nhật lớn nhất bị che phủ bởi các cột?

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve(ll n, vector<ll>& a) {
        stack<ll> st;
        ll res = INT_MIN;
        ll i = 0;
        while (i < n){
            // kiem tra xem chieu dai cua tai hcn do co kha nang noi dai sang ben trai khong
            if (st.empty() || a[i] > a[st.top()]){
                st.push(i);
                i++;
            }
            else{
                ll idx = st.top();
                st.pop();
                if (st.empty()){
                    res = max(res, i * a[idx]); // khong bi chan duoi
                }
                else{
                    res = max(res, a[idx] * (i - st.top() - 1)); // bi chan duoi
                }
            }
        }
        // tinh not dien tich cua nhung hcn con cuoi cung
        while (!st.empty()){
            ll idx = st.top();
            st.pop();
            if (st.empty()){
                res = max(res, i * a[idx]);
            }
            else{
                res = max(res, a[idx] * (i - st.top() - 1));
            }
        }
        cout << res << endl;
    }
};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution sol;
        sol.solve(n, a);
    }
    return 0;
}