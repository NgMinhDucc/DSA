#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> name, current;
vector<bool> used; // mang danh dau
string last;

void HoanVi(){
    if (current.size() == n - 1){
        for (string &name : current){
            cout << name << " ";
        }
        cout << last << endl;
        return;
    } // in ra nhung to hop tim duoc

    for (int i = 0; i < name.size(); i++){
        if (!used[i]){
            used[i] = true;
            current.push_back(name[i]);
            HoanVi();
            current.pop_back();
            used[i] = false;
        }
    }
}

void solution(){
    cin >> n;
    name.resize(n); // khai bao kich thuoc cho mang name
    for (int i = 0; i < n; i++){
        cin >> name[i];
    }
    cin >> last;

    // xoa "last"
    name.erase(remove(name.begin(), name.end(), last), name.end());
    sort(name.begin(), name.end());

    // khai bao mang danh dau
    used.resize(n - 1, false);

    HoanVi();
}

int main(){
    solution();
    return 0;
}