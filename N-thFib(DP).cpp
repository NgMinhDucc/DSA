// Tinh so Fibonacci thu N bang DP
// memoization (top down) method

#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp){
	if (n <= 1) return n;
	
	if (dp[n] != -1) return dp[n];
	
	dp[n] = fib(n - 2, dp) + fib(n - 1, dp);
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	cout << fib(n, dp);
	return 0;
}