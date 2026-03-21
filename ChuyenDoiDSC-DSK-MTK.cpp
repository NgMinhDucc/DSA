#include <bits/stdc++.h>
using namespace std;

int n, m; // khai bao toan cuc cho de truy cap

// chuyen doi tu danh sach canh sang ma tran ke
int a1[1001][1001];
void DSC_MTK(){
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y; // moi lan nhap 1 canh se nhap them cac dinh noi cua canh do
        a1[x][y] = a1[y][x] = 1; // dinh A co canh noi sang dinh B thi dinh B cung vay
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a1[i][j] << " ";
        }
        cout << endl;
    }
}

// chuyen doi tu danh sach canh sang danh sach ke
vector<int> a2[1001]; // mang tinh chua cac vector
void DSC_DSK(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        // day cac dinh vao dsk cua nhau vi cac dinh luon duoc noi voi nhau
        a2[x].push_back(y);
        a2[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int j : a2[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

// chuyen doi tu ma tran ke sang danh sach canh
int a3[1001][1001];
vector<pair<int, int>> e1; // mang luu cac canh doi mot
void MTK_DSC(){
    cin >> n; // mtk luon la ma tran vuong, kinh thuoc = so dinh cua do thi
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a3[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a3[i][j] == 1 && i < j){ // chi luu cac cap i < j neu ko se bi trung vi (i, j) va (j, i) la 1
                e1.push_back({i, j});
            }
        }
    }
    for (auto it : e1){
        cout << it.first << " " << it.second << endl;
    }
}

// chuyen doi tu ma tran ke sang danh sach ke
int a4[1001][1001];
vector<int> adj[1001];
void MTK_DSK(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a4[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a4[i][j] == 1 && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    // // co the lam theo cach nay, se ngan va tien hon
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         if (a4[i][j] == 1){ // vi cac dinh luon noi voi nhau nen chung se luu lan nhau vao dsk cua nhau
    //             adj[i].push_back(j); // nen ko can dieu kien i < j nua
    //         }
    //     }
    // }
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int j : adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

// chuyen doi tu danh sach ke sang ma tran ke
int a5[1001][1001];
void DSK_MTK(){
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++){
        string s;
        getline(cin, s); // nhap vao 1 xau vi ta ko biet trc dc moi dinh cua dsk co bnh dinh ke vs no
        stringstream ss(s);
        string num;
        while (ss >> num){
            a5[i][stoi(num)] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a5[i][j] << " ";
        }
        cout << endl;
    }
}

// chuyen doi tu danh sach ke sang danh sach canh
vector<pair<int, int>> e2;
void DSK_DSC(){
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++){
        string s;
        getline(cin, s); // tuong tu ham tren, ta ko biet trc co bnh dinh ke tai moi dinh, nen ta phai nhap vao nhu 1 xau
        stringstream ss(s);
        string num;
        while (ss >> num){
            if (i < stoi(num)){ // chi luu (i, j), ko luu (j, i) de tranh trung lap
                e2.push_back({i, stoi(num)});
            }
        }
    }
    for (auto it : e2){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    // DSC_MTK(); // line 6
    // DSC_DSK(); // line 24
    // MTK_DSC(); // line 44
    // MTK_DSK(); // line 66
    // DSK_MTK(); // line 101
    // DSK_DSC(); // line 123
    return 0;
}