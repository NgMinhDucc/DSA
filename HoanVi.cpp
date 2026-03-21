#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, dem = 1;
vector<int> res(100);
vector<bool> used(100, false); // ham danh dau

void in(){
    cout << dem << ": ";
    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    dem++;
}

void Test(int i){
    for (int j = 1; j <= n; j++){
        if (!used[j]){
            res[i] = j;
            used[j] = true;
            if (i == n){
                in();
            }
            else{
                Test(i + 1);
            }
            used[j] = false;
        }
    }
}

int main(){
    cin >> n;
    Test(1);
    return 0;
}