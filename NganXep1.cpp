// NGAN XEP 1: Co 3 cau lenh push, pop, va show. Viet code nhap vao cac cau lenh (ko nhap so luong) va ghi ra ket qua cua lenh show

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    stack<int> st;
    int n;
    string cmd;
    while (cin >> cmd){
        if (cmd == "push"){ // day 1 phan tu vao trong stack
            cin >> n;
            st.push(n);
        }
        if (cmd == "pop"){ // xoa 1 phan tu ra khoi stack
            st.pop();
        }
        if (cmd == "show"){ // in ra ket qua cua cac cau lenh
            if (st.empty()){
                cout << "empty\n";
            }
            else{
                vector<int> save; // luu cac phan tu co duoc sau moi cau lenh
                stack<int> temp = st; // stack temp de khong lam anh huong toi stack goc
                while (!temp.empty()){
                    save.push_back(temp.top());
                    temp.pop();
                }
                reverse(save.begin(), save.end());
                for (int i = 0; i < save.size(); i++){
                    cout << save[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}