#include <iostream>
#include <chrono>
#include <iomanip>
#include "../include/solution.h"
using namespace std;
using namespace chrono;

// Helper para construir una lista secuencial de 1 a n
Node* buildListSeq(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 1; i <= n; i++) {
        Node* u = new Node(i);
        if (!head) head = tail = u;
        else { tail->next = u; tail = u; }
    }
    return head;
}

// Helper para construir SLList secuencial de 1 a n
SLList buildSLListSeq(int n) {
    SLList list;
    for (int i = 1; i <= n; i++) list.add(i);
    return list;
}

// Helper para liberar memoria de la lista
void freeList(Node* head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

template<typename Func>
double medir(Func f, int repeticiones) {
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < repeticiones; i++) { f(); }
    auto t2 = high_resolution_clock::now();
    return duration<double, milli>(t2 - t1).count() / repeticiones;
}

int main() {
    int tamanios[] = {100, 1000, 10000, 100000};
    int REP = 10;

    cout << fixed << setprecision(4) << left;
    cout << setw(12) << "Tamaño"
        << setw(25) << "Opcion A O(n^2) ms"
        << setw(25) << "Opcion B O(n) ms" << "\n";
    cout << string(60, '-') << "\n";

    for (int n : tamanios) {
        int k = n / 2;

        double msA = medir([&]() {
            SLList list = buildSLListSeq(n);
            reverseKGroupValues(list, k);
        }, REP);

        double msB = medir([&]() {
            Node* list = buildListSeq(n);
            list = reverseKGroupNodes(list, k);
            freeList(list);
        }, REP);

        cout << setw(12) << n
            << setw(25) << msA
            << setw(25) << msB << "\n";
    }

    return 0;
}