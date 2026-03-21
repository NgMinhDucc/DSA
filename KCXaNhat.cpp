// Khoang cach xa nhat: Tim cap vi tri sao cho j - i lon nhat va Aj > Ai

#include <bits/stdc++.h>
using namespace std;

int kc(int n, pair<int, int> a[]){
	int res = -1, x = a[0].first, Min = a[0].second;
	
	for (int i = 1; i < n; i++){
		if (a[i].first > x){
			res = max(res, a[i].second - Min); // cap nhat hieu (j, i) neu so sau > so truoc
		}
		
		if (a[i].second < Min){ // neu idx hien tai < idx truoc do thap cap nhat Min va x (Li do: sbt tang, st giam -> hieu tang)
			x = a[i].first;
			Min = a[i].second;
		}
	}
	
	return res;
}

int main(){
	int test;
	cin >> test;
	while (test--){
		int n;
		cin >> n;
		pair<int, int> a[n]; // luu theo cap -> giu duoc cap (a[i], i)
		for (int i = 0; i < n; i++){
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);
		
		cout << kc(n, a) << endl;
	}
	return 0;
}