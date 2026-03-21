// XAU CON NHO NHAT CHUA DAY DU CAC KI TU CUA S

#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	cin >> test;
	while (test--){
		string s;
		cin >> s;
		unordered_set<char> cha(s.begin(), s.end());
		int si = cha.size();
		unordered_map<char, int> freq;
		int l = 0, dem = 0, min_len = 1e9;
		for (int i = 0; i < s.length(); i++){
			freq[s[i]]++;
			if (freq[s[i]] == 1) dem++;
			while (dem == si){
				min_len = min(min_len, i - l + 1);
				freq[s[l]]--;
				if (freq[s[l]] == 0) dem--;
				l++;
			}
		}
		cout << min_len << endl;
	}
	return 0;
}