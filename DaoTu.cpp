// DAO TU: Dao nguoc tung tu trong xau

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    cin.ignore();
    while (test--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string words;
        vector<string> save;
        int n = save.size();
        while (ss >> words) save.push_back(words);
        for (int i = 0; i < n; i++) reverse(save[i].begin(), save[i].end());
        for (int i = 0; i < n; i++) cout << save[i] << " ";
        cout << endl;
    }
    return 0;
}