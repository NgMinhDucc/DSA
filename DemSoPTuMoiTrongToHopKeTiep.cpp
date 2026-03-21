// DEM SO PHAN TU MOI: Nhap vao 1 to hop, hay dem xem co bao nhieu phan tu moi trong to hop ke tiep cua to hop da nhap
// Neu to hop vua nhap la to hop cuoi, thi so phan tu moi la k

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int n, k;
// vector<int> res(101, 0);
// vector<vector<int>> save;

// void in(){
//     vector<int> temp;
//     for (int i = 1; i <= k; i++){
//         temp.push_back(res[i]);
//     }
//     save.push_back(temp);
// }

// j = res[i - 1] + 1
// j = n - k + i
// void QuayLui(int i){
//     for (int j = res[i - 1] + 1; j <= n - k + i; j++){
//         res[i] = j;
//         if (i == k){
//             in();
//         }
//         else{
//             QuayLui(i + 1);
//         }
//     }
// }

// int main(){
//     int test;
//     cin >> test;
//     while (test--){
//         cin >> n >> k;
//         res.resize(k + 1);
//         save.clear(); // luon phai nho cai nay
//         QuayLui(1);
//         // nhap to hop
//         vector<int> num(k);
//         for (int i = 0; i < k; i++){
//             cin >> num[i];
//         }
//         // tim vi tri cua to hop vua nhap
//         int pos = -1, m = save.size();
//         for (int i = 0; i < m; i++){
//             if (num == save[i]){
//                 pos = i;
//                 break;
//             }
//         }
//         // dem so phan tu moi
//         int count = 0;
//         if (pos == m - 1){
//             count = k;
//         }
//         else{
//             vector<int> next = save[pos + 1];
//             for (int i : next){
//                 if (find(num.begin(), num.end(), i) == num.end()){
//                     count++;
//                 }
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }

int n, k;
// tim to hop ke tiep thay vi sinh tat ca
bool Tim(vector<int> &a){
    int i = k - 1; // vi tri ngoai cung ben phai co the tang
    while (i >= 0 && a[i] == n - k + i + 1){
        i--;
    }
    if (i < 0){
        return false; // neu khong tim duoc thi to hop da nhap la to hop cuoi
    }
    a[i]++; // tang phan tu tim duoc
    for (int j = i + 1; j < k; j++){
        a[j] = a[j - 1] + 1; // dat cac phan tu ben phai ve gia tri nho nhat
    }
    return true;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        cin >> n >> k;
        vector<int> num(k);
        for (int i = 0; i < k; i++){
            cin >> num[i];
        }
        vector<int> next = num;
        int count = 0;
        if (!Tim(next)){
            count = k;
        }
        else{
            for (int i : next){
                if (find(num.begin(), num.end(), i) == num.end()){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}