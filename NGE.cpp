// NEXT GREATER ELEMENT (NGE): Cho mang A. Voi moi A[i], tim phan tu dau tien ben phai lon hon no

#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	cin >> test;
	while (test--){
		int n;
		cin >> n;
		vector<int> num(n), res(n);
		for (int i = 0; i < n; i++){
			cin >> num[i];
		}
		stack<int> st;
		for (int i = 0; i < n; i++){
			if (st.empty()){ // neu stack rong thi day chi so cua phan tu thu i vao
				st.push(i);
			}
			else{
				while (!st.empty() && num[st.top()] < num[i]){
					// neu ptu o vi tri dau stack < phan tu thu i thi gan gtri cua ptu thu i cho ptu o vi tri dau stack
					res[st.top()] = num[i];
					// xoa ptu dau stack va day chi so cua ptu thu i vao
					st.pop();
				}
				st.push(i);
			}
		}
		// gan -1 cho nhung ptu lon nhat mang
		while (!st.empty()){
			res[st.top()] = -1;
			st.pop();
		}
		for (int i : res){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}