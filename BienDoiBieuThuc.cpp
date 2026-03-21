#include <bits/stdc++.h>
using namespace std;

string convert(string s){
	stack<char> st;
	vector<string> save(s.length());
	for (int i = 0; i < (int)s.length(); i++){
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')'){
			if (!st.empty()){
				int t = st.top(); st.pop();
				save[t] = "0";
				save[i] = "1";
			}
			else save[i] = "-1";
		}
		else{
			save[i] = string(1, s[i]);
		}
	}

	while(!st.empty()){
		int t = st.top(); st.pop();
		save[t] = "-1";
	}

	string res = "";
	for (int i = 0; i < (int)save.size(); i++){
		res += save[i];
	}
	return res;
}

int main(){
	int test;
	cin >> test;
	while (test--){
		string s;
		cin >> s;

		cout << convert(s) << endl;
	}
	return 0;
}
