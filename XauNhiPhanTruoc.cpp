// XAU NHI PHA TRUOC: In ra xau nhi phan lien truoc cua xau dc nhap tu input

#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        string bi;
        cin >> bi;
        bool mark = false;
        for (int i = bi.length() - 1; i >= 0; i--){
            if (bi[i]== '1'){ // neu so cuoi la 1 thi chi can doi thanh 0
                bi[i] = '0';
                mark = true;
                break;
            }
            else{
                bi[i] = '1'; // neu gap so 0, tiep tuc duyet
            }
        }
        if (!mark){
            for (int i = bi.length() - 1; i >= 0; i--){
                bi[i] = '1';
            }
        }
        cout << bi << endl;
    }
    return 0;
}