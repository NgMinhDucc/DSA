// BAI TOAN N QUAN HAU: Dat cac quan hau sau cho chung khong an lan nhau

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a(11, 0);
vector<bool> cot(11, false), xuoi(2 * 11 - 1, false), nguoc(2 * 11 - 1, false);

void in(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i] == j) cout << "X "; // neu co quan hau tai (i, j) thi danh dau X
            else cout << "O ";
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]){ // kiem tra xem co the dat quan hau tai (i, j) khong
            a[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = true; // danh dau cot va 2 duong cheo la da co quan hau quan li
            if (i == n) in(); // in cau hinh sau khi da dat du n quan hau
            else Try(i + 1); // neu chua thi tiep tuc duyen toi hang tiep theo
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = false; // bo danh dau quan hau o cot j hien tai de xet toi quan hau o cot j ke tiep
        }
    }
}

int main(){
    cin >> n;
    Try(1);
    return 0;
}