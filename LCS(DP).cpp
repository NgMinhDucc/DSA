// LCS: Longest Common Subsequence - Day con chung dai nhat
// In ra do dai cua day con chung dai nhat cua 2 xau

#include <bits/stdc++.h>
using namespace std;

// Can 1 mang luu do dai cua xau chung tai ki tu thu i cua xau 1
// L[i][0] = 0, L[0][j] = 0 (Do dai xau chung ban dau = 0)
// s1[i] = s2[j] --> L[i][j] = L[i-1][j-1] + 1
// s1[i] != s2[j] --> L[i][j] = max(L[i-1][j], L[i][j-1])

void LCS(string s1, string s2){
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> le(n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if (i == 0 || j == 0){
				le[i][j] = 0;
			}
			else if (s1[i - 1] == s2[j - 1]){
				le[i][j] = le[i - 1][j - 1] + 1;
			}
			else{
				le[i][j] = max(le[i - 1][j], le[i][j - 1]);
			}
		}
	}
	cout << le[n][m] << endl;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		string s1, s2;
		cin >> s1 >> s2;
		LCS(s1, s2);
	}
	return 0;
}