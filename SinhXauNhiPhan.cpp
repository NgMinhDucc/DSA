#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> res;

void in(){
    for (int i = 1; i <= n; i++){
        cout << res[i];
    }
    cout << endl;
}

void Test(int k){
    // duyet cac kha nang cua res[i]
    for (int i = 0; i <= 1; i++){
        res[k] = i;
        if (k == n){ // xay dung den bit cuoi thi in ket qua
            in();
        }
        else{
            Test(k + 1);
        }
    }
}

int main(){
    cin >> n;
    res.resize(n + 1);
    Test(1);
    return 0;
}