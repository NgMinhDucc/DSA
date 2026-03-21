// Xau nhi phan ke tiep: In ra xau nhi phan ke tiep cua xau da cho

#include <bits/stdc++.h>
using namespace std;

string next_bi(string s){
	int i = s.length() - 1;
	while (i >= 0 && s[i] == '1'){
		i--;
	}
	if (i < 0){
		for (int j = 0; j < (int)s.length(); j++){
			s[j] = '0';
		}
		return s;
	}
	else{
		s[i] = '1';
		for (int j = i + 1; j < (int)s.length(); j++){
			s[j] = '0';
		}
		return s;
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		
		string res = next_bi(s);
		cout << res << endl;
	}
	return 0;
}
