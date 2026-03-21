// SO LOC PHAT: In ra cac so loc phat co N chu so

#include <bits/stdc++.h>
using namespace std;

vector<string> res; // luu cac so loc phat
vector<string> save; // luu cac phan tu cua res

void SoLocPhat(int n, queue<string> q){
    q.push("6");
    q.push("8");
    res.push_back("6");
    res.push_back("8");
    while (!q.empty()){
        string top = q.front();
        q.pop();
        if (top.length() == n){
            break;
        }
        res.push_back(top + "6");
        res.push_back(top + "8");
        q.push(top + "6");
        q.push(top + "8");
    }
    for (string s : res){
        save.push_back(s);
    }
    reverse(save.begin(), save.end());
    cout << save.size() << endl;
    for (int i = 0; i < save.size(); i++){
        cout << save[i] << " ";
    }
    cout << endl;
    res.clear();
    save.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--){
        int n; // so chu so cua so loc phat
        cin >> n;
        queue<string> q;
        SoLocPhat(n, q);
    }
    return 0;
}