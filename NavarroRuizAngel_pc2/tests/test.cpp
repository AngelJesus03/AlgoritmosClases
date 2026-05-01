#include <cassert>
#include <iostream>
#include <string>
#include "../include/solution.h"
using namespace std;

// Helper para construir una lista desde un arreglo
Node* buildList(int vals[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < size; i++) {
        Node* u = new Node(vals[i]);
        if (!head) head = tail = u;
        else { tail->next = u; tail = u; }
    }
    return head;
}

// Helper para verificar que la lista tiene los valores esperados
void checkList(Node* head, int expected[], int size) {
    for (int i = 0; i < size; i++) {
        assert(head != nullptr);
        assert(head->x == expected[i]);
        head = head->next;
    }
    assert(head == nullptr);
}

void ejecutar_test(int vals[], int size, int expected[], int k, const string& nombre) {
    Node* list = buildList(vals, size);
    list = reverseKGroupNodes(list, k);
    checkList(list, expected, size);
    cout << nombre << " paso" << endl;
}

int main() {

    // Caso 1: Normal
    int v1[] = {1, 2, 3, 4, 5};
    int v2[] = {7, 14, 3, 22, 9};
    int e1[] = {2, 1, 4, 3, 5};
    int e2[] = {3, 14, 7, 22, 9};

    // Caso 2: k=1
    int v3[] = {1, 2, 3, 4, 5};
    int v4[] = {7, 14, 3, 22, 9};
    int e3[] = {1, 2, 3, 4, 5};
    int e4[] = {7, 14, 3, 22, 9};

    // Caso 3: k=n
    int v5[] = {1, 2, 3, 4, 5};
    int v6[] = {7, 14, 3, 22, 9};
    int e5[] = {5, 4, 3, 2, 1};
    int e6[] = {9, 22, 3, 14, 7};

    // Caso 4: k > nodos restantes
    int v7[] = {1, 2, 3, 4, 5};
    int v8[] = {7, 14, 3, 22, 9};
    int e7[] = {4, 3, 2, 1, 5};
    int e8[] = {22, 3, 14, 7, 9};

    // Caso 5: un solo elemento
    int v9[]  = {1};
    int v10[] = {42};
    int e9[]  = {1};
    int e10[] = {42};

    cout << "Ejecutando tests con la funcion 'reverseKGroupNodes'\n" << endl;

    ejecutar_test(v1,  5, e1,  2, "Caso normal 1");
    ejecutar_test(v2,  5, e2,  3, "Caso normal 2");
    ejecutar_test(v3,  5, e3,  1, "Caso k=1 1");
    ejecutar_test(v4,  5, e4,  1, "Caso k=1 2");
    ejecutar_test(v5,  5, e5,  5, "Caso k=n 1");
    ejecutar_test(v6,  5, e6,  5, "Caso k=n 2");
    ejecutar_test(v7,  5, e7,  4, "Caso k>nodos restantes 1");
    ejecutar_test(v8,  5, e8,  4, "Caso k>nodos restantes 2");
    ejecutar_test(v9,  1, e9,  1, "Caso un elemento 1");
    ejecutar_test(v10, 1, e10, 1, "Caso un elemento 2");

    cout << "\nTodos los tests pasaron" << endl;
    return 0;
}