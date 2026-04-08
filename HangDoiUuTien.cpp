#include <bits/stdc++.h>
using namespace std;

// cach thao tac push, size, empty giong het queue

int main()
{
    priority_queue<int> pq;
    vector<int> a = {1, 3, 4, 2, 5, 9};

    for (int i : a)
    {
        pq.push(i);
    }
    // top lay ra phan tu o dau, pq, mac dinh la lon nhat
    cout << pq.top() << endl; // 9
    pq.pop(); // xoa phan tu o dau
    cout << pq.top() << endl; // 5

    priority_queue<int, vector<int>, greater<int>> pq2; // phan tu o dau la nho nhat
    vector<int> b = {100, 200, 4000, 902, 403};

    for (int i : b)
    {
        pq2.push(i);
    }
    cout << pq2.top() << endl; // 100
    return 0;
}