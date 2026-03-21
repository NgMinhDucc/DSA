/*
Cho mảng A[] gồm n phần tử. Hãy đưa ra các phần tử nhỏ hơn tiếp theo của phần tử lớn hơn đầu tiên
phần tử hiện tại. Nếu phần tử hiện tại không có phần tử lớn hơn tiếp theo ta xem là -1. Nếu phần tử
không có phần tử nhỏ hơn tiếp theo ta cũng xem là -1. Ví dụ với mảng A[] = {5, 1, 9, 2, 5, 1, 7} ta có kết 
quả là ans = {2, 2, -1, 1, -1, -1, -1} vì:
Next Greater                  Right Smaller

5 ->  9                       9  ->  2

1 ->  9                       9  ->  2

9 -> -1                      -1 -> -1

2 -> 5                        5   -> 1

5 -> 7                        7  -> -1

1 ->  7                       7 -> -1

7 -> -1                       7 -> -1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, vector<int>& a) {
        stack<int> st1, st2;
        vector<int> maxx(n), minn(n);
        // tim phan tu dau tien lon hon ben phai
        for (int i = 0; i < n; i++){
            if (st1.empty()) st1.push(i);
            else{
                while (!st1.empty() && a[i] > a[st1.top()]){
                    maxx[st1.top()] = i; // luu chi so
                    st1.pop();
                }
                st1.push(i);
            }
        }
        while (!st1.empty()){
            maxx[st1.top()] = -1;
            st1.pop();
        }
        // tim phan tu dau tien nho hon ben phai
        for (int i = 0; i < n; i++){
            if (st2.empty()) st2.push(i);
            else{
                while (!st2.empty() && a[i] < a[st2.top()]){
                    minn[st2.top()] = i; // luu chi so
                    st2.pop();
                }
                st2.push(i);
            }
        }
        while (!st2.empty()){
            minn[st2.top()] = -1;
            st2.pop();
        }
        // in ket qua
        for (int i = 0; i < n; i++){
            if (maxx[i] == -1 || minn[maxx[i]] == -1){
                cout << -1 << " ";
            }
            else{
                cout << a[minn[maxx[i]]] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution sol;
        sol.solve(n, a);
    }
    return 0;
}