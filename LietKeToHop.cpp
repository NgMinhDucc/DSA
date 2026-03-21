// LIET KE TO HOP: Cho mang A gom n phan tu, liet ke to hop chap k tu cac phan tu trong A

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> num(100), res(100 ,0);
vector<bool> used(100, false);
set<int> temp;
vector<int> save;

void in(){
    for (int i = 0; i < k; i++) cout << res[i] << " ";
    cout << endl;
}

void QuayLui(int i, int start){
    for (int j = start; j < save.size(); j++){
        if (!used[j]){
            res[i] = save[j];
            used[j] = true;
            if (i == k - 1) in();
            else QuayLui(i + 1, j + 1);
            used[j] = false; // quay lui
        }
    }
}

int main(){
    cin >> n >> k;
    num.resize(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i : num) temp.insert(i);
    for (int i : temp) save.push_back(i);
    res.resize(k);
    used.resize(k);
    QuayLui(0, 0);
    return 0;
}