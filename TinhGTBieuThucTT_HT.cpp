#include <bits/stdc++.h>
#define ll long long
using namespace std;

string cal_hauto(int n, vector<string>& s) {
	stack<ll> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") {
			long long b = st.top(); st.pop();
			long long a = st.top(); st.pop();

			if (s[i] == "+") st.push(a + b);
			if (s[i] == "-") st.push(a - b);
			if (s[i] == "*") st.push(a * b);
			if (s[i] == "/") st.push(a / b);
		}
		else st.push(stoll(s[i]));
	}
	return to_string(st.top());
}

string cal_tiento(int n, vector<string>& s){
	stack<ll> st;
	for (int i = n - 1; i >= 0; i--){
		if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/"){
			long long a = st.top(); st.pop();
			long long b = st.top(); st.pop();
			
			if (s[i] == "+") st.push(a + b);
			if (s[i] == "-") st.push(a - b);
			if (s[i] == "*") st.push(a * b);
			if (s[i] == "/") st.push(a / b);
		}
		else{
			st.push(stoll(s[i]));
		}
	}
	return to_string(st.top());
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		
		if (s[0] == "+" || s[0] == "-" || s[0] == "*" || s[0] == "/"){
			cout << cal_tiento(n, s) << endl;
		}
		else{
			cout << cal_hauto(n, s) << endl;
		}
	}
	return 0;
}
