// HOAN VI CHU SO: Liet ke tat ca cac so nguyen co the tao tu so n, khong tinh truong hop so 0 dung o dau

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a(10), res(10, 0); 
vector<bool> used(10, false); // mang danh dau
vector<string> save; // luu cac to hop dang string vao 1 mang

void in(){
    string temp;
    // luu cac to hop nhu 1 string
    for (int i = 1; i <= n; i++){
        if (temp.length() == 0 && a[res[i]] == 0){
            continue;
        }
        temp += to_string(a[res[i]]);
    }
    save.push_back(temp);
}

void Try(int k){
    for (int i = 1; i <= n; i++){
        if (!used[i]){
            res[k] = i;
            used[i] = true;
            if (k == n){
                in();
            }
            else{
                Try(k + 1);
            }
            used[i] = false;
        }
    }
}

bool sapxep(string a, string b){
    if (a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}

int main(){
    int test;
    cin >> test;
    while (test--){
        string s;
        cin >> s;
        n = s.length();
        for (int i = 0; i < n; i++){
            a[i + 1] = s[i] - '0';
        } // chuyen cac phan tu cua xau s vao mang a
        Try(1);
        sort(save.begin(), save.end(), sapxep);
        int m = save.size();
        for (int i = 0; i < m; i++){
            cout << save[i] << endl;
        }
        save.clear(); // lam rong mang de khong lam xao tron gia tri o cac case ke tiep
    }
    return 0;
}