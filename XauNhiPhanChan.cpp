#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
vector<int> a(100);

void in(){
    int count = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == 1){
            count++;
        }
    }
    if (count % 2 == 0){
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void quaylui(int i){
    for (int j = 0; j <= 1; j++){
        a[i] = j;
        if (i == n){
            in();
        }
        else{
            quaylui(i + 1);
        }
    }
}

int main(){
    cin >> n;
    quaylui(1);
    return 0;
}