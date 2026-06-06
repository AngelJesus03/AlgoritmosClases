#include "../include/solution.h"

int main() {

    // Ejemplo 1: [3,7,1,9,2] con k=2
    cout << "=== Ejemplo 1 ===" << "\n";
    int vals1[] = {3, 7, 1, 9, 2};
    Node* l1 = nullptr;
    Node* tail1 = nullptr;
    for (int i = 0; i < 5; i++) {
        Node* u = new Node(vals1[i]);
        if (!l1) l1 = tail1 = u;
        else { tail1->next = u; tail1 = u; }
    }
    cout << "Input:  "; printNodes(l1);
    l1 = reverseKGroupNodes(l1, 2);
    cout << "k=2  -> "; printNodes(l1);

    cout << "\n";

    // Ejemplo 2: [5,12,8,4,6,11] con k=3
    cout << "=== Ejemplo 2 ===" << "\n";
    int vals2[] = {5, 12, 8, 4, 6, 11};
    Node* l2 = nullptr;
    Node* tail2 = nullptr;
    for (int i = 0; i < 6; i++) {
        Node* u = new Node(vals2[i]);
        if (!l2) l2 = tail2 = u;
        else { tail2->next = u; tail2 = u; }
    }
    cout << "Input:  "; printNodes(l2);
    l2 = reverseKGroupNodes(l2, 3);
    cout << "k=3  -> "; printNodes(l2);

    cout << "\n";

    // Ejemplo 3: [13,14,15,16,17,18] con k=4 (k > n/2)
    cout << "=== Ejemplo 3 ===" << "\n";
    int vals3[] = {13, 14, 15, 16, 17, 18};
    Node* l3 = nullptr;
    Node* tail3 = nullptr;
    for (int i = 0; i < 6; i++) {
        Node* u = new Node(vals3[i]);
        if (!l3) l3 = tail3 = u;
        else { tail3->next = u; tail3 = u; }
    }
    cout << "Input:  "; printNodes(l3);
    l3 = reverseKGroupNodes(l3, 4);
    cout << "k=4  -> "; printNodes(l3);

    cout << "\n";

    // Ejemplo 4: [21,35,42,17,53,8] con k=5 (k > n/2)
    cout << "=== Ejemplo 4 ===" << "\n";
    int vals4[] = {21, 35, 42, 17, 53, 8};
    Node* l4 = nullptr;
    Node* tail4 = nullptr;
    for (int i = 0; i < 6; i++) {
        Node* u = new Node(vals4[i]);
        if (!l4) l4 = tail4 = u;
        else { tail4->next = u; tail4 = u; }
    }
    cout << "Input:  "; printNodes(l4);
    l4 = reverseKGroupNodes(l4, 5);
    cout << "k=5  -> "; printNodes(l4);

    return 0;
}