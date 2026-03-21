// XAU NHI PHAN KE TIEP: In ra xau nhi han lien sau cua xau vua nhap
// Khong dung next_permutation do ham nay chi sinh ra hoan vi (sai ban chat)

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
            if (bi[i] == '0'){
                bi[i] = '1';
                for (int j = i + 1; j < bi.length(); j++){
                    bi[j] = '0';
                }
                mark = true;
                break; // chi doi 1 lan
            }
        }
        if (!mark){
            for (int i = 0; i < bi.length(); i++){
                bi[i] = '0';
            }
        }
        cout << bi << endl;
    }
    return 0;
}