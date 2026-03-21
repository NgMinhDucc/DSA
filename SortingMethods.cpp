#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int n, int a[]){
    int step = 1;
    for (int i = 0; i < n - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (a[min_idx] > a[j]){
                min_idx = j;
            }
        }
        swap(a[min_idx], a[i]);
        cout << "Buoc " << step << ": ";
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        step++;
    }
}

void InsertionSort(int n, int a[]){
    int step = 1;
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = key;
        cout << "Buoc " << step << ": ";
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        step++;
    }
}

void Merge(int a[], int l, int m, int r){
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size()){
        if (x[i] <= y[j]){
            a[l++] = x[i++];
        }
        else{
            a[l++] = y[j++];
        }
    }
    while (i < x.size()){
        a[l++] = x[i++];
    }
    while (j < y.size()){
        a[l++] = y[j++];
    }
}

void MergeSort(int a[], int l, int r){
    if (l >= r){
        return ;
    }
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r); // tron 2 phan nua cua day sau khi sap xep
}

int partition(int a[], int l, int r){
    int i = l - 1, pivot = a[r];
    for (int j = l; j < r; j++){
        if (a[j] <= pivot){
            i++;
            swap(a[j], a[i]);
        }
    }
    i++;
    swap(a[r], a[i]);
    return i;
}

void QuickSort(int a[], int l, int r){
    if (l < r){
        int p = partition(a, l, r);
        QuickSort(a, l, p - 1);
        QuickSort(a, p + 1, r);
    }
}

void Solution(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    //SelectionSort(n, a);
    //InsertionSort(n, a);
    //MergeSort(a, 0, n - 1);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

void Test(){
    int test;
    cin >> test;
    while (test--){
        Solution();
    }
}

int main(){
    //Test();
    Solution();
    return 0;
}