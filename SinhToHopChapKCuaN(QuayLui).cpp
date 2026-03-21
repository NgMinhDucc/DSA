#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> res(100);

void in(){
    for (int i = 1; i <= k; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

void Test(int i){
    for (int j = res[i - 1] + 1; j <= n - k + i; j++){
        res[i] = j;
        if (i == k){
            in();
        }
        else{
            Test(i + 1);
        }
    }
}

int main(){
    cin >> n >> k;
    res.resize(k + 1);
    res[0] = 0;
    Test(1);
    return 0;
}