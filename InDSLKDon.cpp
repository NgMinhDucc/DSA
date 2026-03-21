// In DSLK don
// Xoa node dau/giua/cuoi

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* node;

node makeNode(vector<int>& a) {
    node head = new Node();
    head->data = a[0];
    head->next = NULL;

    node temp = head;
    for (int i = 1; i < (int)a.size(); i++) {
        node newNode = new Node();
        newNode->data = a[i];
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

// xoa dau
void deleteFirst(node& head) {
    if (head == NULL) return;
    node needDel = head;
    head = head->next;
    delete needDel;
}

// xoa cuoi
void deleteLast(node& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        node needDel = head;
        head = NULL;
        delete needDel;
        return;
    }
    node temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    node last = temp->next;
    temp->next = NULL;
    delete last;
}

// xoa giua
void deleteMiddle(node& head, int pos) {
    int n = sizeof(head);
    if (pos <= 0 || pos > n) return;
    else if (pos == 1) deleteFirst(head);
    else if (pos == n) deleteLast(head);
    else {
        node temp = head;
        for (int i = 1; i <= pos - 2; i++) {
            temp = temp->next;
        }
        node p = temp->next;
        temp->next = p->next;
        delete p;
    }
}

void printLinkedList(node& head) {
    node temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    vector<int> a = { 1, 2, 100000000, 4, 5 };
    node head = makeNode(a);
    int pos;
    cin >> pos;
    deleteMiddle(head, pos);
    printLinkedList(head);
    return 0;
}