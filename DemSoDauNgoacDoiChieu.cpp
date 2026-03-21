// DEM SO DAU NGOAC DOI CHIEU: Dem so dau ngoac can doi chieu de co 1 day ngoac don hop le

#include <bits/stdc++.h>
using namespace std;

int ValidParentheses(string s){
	int open = 0, close = 0;
	for (char c : s){
		if (c == '('){
			open++; // dem so dau mo ngoac
		}
		else{
			if (open > 0){
				open--; // neu gap duoc dau dong ngoac thi giam so luong dau mo ngoac
			}
			else{
				close++; // khong thi tang so luong dau dong ngoac
			}
		}
	}
	// cong thuc tinh so phep doi
	return (open + 1) / 2 + (close + 1) / 2;
}

int main(){
	int test;
	cin >> test;
	while (test--){
		string par;
		cin >> par;
		cout << ValidParentheses(par) << endl;
	}
	return 0;
}