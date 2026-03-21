// DAY SO 2: Tuong tu DaySo1, nhung in nguoc lai va tren cung 1 dong

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> save; // luu cac thanh phan mang tinh duoc

void in(){
    for (int i = 0; i < save.size(); i++){
        cout << "[";
        for (int j = 0; j < save[i].size(); j++){
            if (j < save[i].size() - 1){
                cout << save[i][j] << " ";
            }
            else{
                cout << save[i][j] << "] ";
            }
        }
    }
}

void build(vector<int> a){
    vector<int> temp;
    if (a.size() == 1){
        return;
    }
    else{
        for (int i = 0; i < a.size() - 1; i++){
            temp.push_back(a[i] + a[i + 1]);
        }
        save.push_back(temp);
        build(temp);
    }
}

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        for (int i = 0; i < save.size(); i++){
            save[i].clear();
        }
        save.clear();
        vector<int> num(n);
        for (int i = 0; i < n; i++){
            cin >> num[i];
        }
        build(num);
        reverse(save.begin(), save.end()); // dao nguoc thu tu cac thanh phan
        for (int i = 0; i < save.size(); i++){
            cout << "[";
            for (int j = 0; j < save[i].size(); j++){
                if (j < save[i].size() - 1){
                    cout << save[i][j] << " ";
                }
                else{
                    cout << save[i][j] << "] ";
                }
            }
        }
        // in ra mang goc
        cout << "[";
        for (int i = 0; i < n; i++){
            if (i < n - 1){
                cout << num[i] << " ";
            }
            else{
                cout << num[i] << "]\n";
            }
        }
    }
    return 0;
}