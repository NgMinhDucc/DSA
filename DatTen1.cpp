// DAT TEN 1: IN RA CAC TO HOP KHAC NHAU DOI MOT, TUC KHONG CAI NAO TRUNG CAI NAO

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
vector<string> a(101);
vector<string> res(101);

void in(){
    for (int i = 0; i < k; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

void Try(int i, int h){
    for (int j = h; j < a.size(); j++){ // duyet tu phan tu thu h tro di, tuc la duyet cac phan tu tiep theo trong mang
        res[i] = a[j];
        if (i == k - 1){
            in();
        }
        else{
            Try(i + 1, j + 1);
        }
    }
}

int main(){
    cin >> n >> k;
    a.resize(n);
    res.resize(k);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<string> temp; // mang luu to hop duy nhat 1 lan
    temp.push_back(a[0]);
    for (int i = 1; i < n; i++){
        if (a[i] != a[i - 1]){
            temp.push_back(a[i]);
        }
    }
    a = temp;
    Try(0, 0);
    return 0;
}
