// Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D. Ký tự I được hiểu là tăng (Increasing) ký tự D được hiểu là giảm (Decreasing). Sử
// dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất được đoán nhận từ S. Chú ý, các số không được phép lặp lại. Dưới đây là một số
// ví dụ mẫu:
// A[] = “I”            : số tăng nhỏ nhất là 12.
// A[] = “D”            : số giảm nhỏ nhất là 21
// A[] = ”DD”           : số giảm nhỏ nhất là 321
// A[] = “DDIDDIID”     : số thỏa mãn 321654798

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(string s){
        s += 'I';
        stack<int> st;
        st.push(-1);
        int maxx = 0;
        for (int i = 0; i < int(s.length()); i++){
            if (s[i] == 'I'){ // tim ki tu I roi thuc hien tat ca cac buoc truoc do
                int step = i - st.top(); // so buoc can thuc hien
                st.pop();
                st.push(i);
                maxx += step; // gia tri lon nhat vua du tai buoc do
                for (int j = maxx; j > maxx - step; j--){
                    cout << j;
                }
            }
        }
        cout << endl;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        Solution sol;
        sol.solve(s);
    }
    return 0;
}