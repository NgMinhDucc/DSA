// DAY SO 1: Cho dãy số A[] gồm n số nguyên dương.
//Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ 1 là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i-1 (2≤i≤n)
// [1, 2, 3, 4, 5]
// [3, 5, 7, 9]
// [8, 12, 16]
// [20, 28]
// [48]

#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int test;
//     cin >> test;
//     while (test--){
//         int n;
//         cin >> n;
//         vector<int> num(n);
//         for (int i = 0; i < n; i++){
//             cin >> num[i];
//         }
//         for (int i = n; i >= 1; i--){
//             // in ra hang hien tai
//             cout << "[";
//             for (int j = 0; j < i; j++){
//                 if (j < i - 1){
//                     cout << num[j] << " ";
//                 }
//                 else{
//                     cout << num[j];
//                 }
//             }
//             cout << "]" << endl;
//             // tinh cac phan tu moi cho hang tiep theo
//             for (int j = 0; j < i - 1; j++){
//                 num[j] = num[j] + num[j + 1];
//             }
//         }
//     }
//     return 0;
// }

void in(vector<int> a){
    cout << "[";
    for (int i = 0; i < a.size(); i++){
        if (i < a.size() - 1){
            cout << a[i] << " ";
        }
        else{
            cout << a[i];
        }
    }
    cout << "]" << endl;
}

// ham de quy: tao xong mang roi in luon, khong can luu
void build(vector<int> a){
    in(a);
    vector<int> temp;
    if (a.size() == 1){ // dieu kien dung
        return;
    }
    else{
        for (int i = 0; i < a.size() - 1; i++){
            temp.push_back(a[i] + a[i + 1]);
        }
        build(temp); // goi de quy de tao hang tiep theo
    }
}

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
        build(num);
    }
    return 0;
}