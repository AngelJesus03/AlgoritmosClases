#include <cassert>
#include <iostream>
#include "../include/solution.h"
using namespace std;

void ejecutar_test(int x[], int n, int p[], int esperado[], const string& nombre){
    ods::SegmentTree st;
    st.n = n;
    st.build(1, 1, n);
    for(int i = 0; i < n; i++){
        int idx = st.kesimo(1, 1, n, p[i]);
        assert(x[idx] == esperado[i]);
        st.remove(1, 1, n, idx);
    }
    cout << nombre << " paso" << endl;
}

void comparar_con_ingenua(int x[], int n, int p[], const string& nombre){
    int res_st[200005];
    ods::SegmentTree st;
    st.n = n;
    st.build(1, 1, n);
    for(int i = 0; i < n; i++){
        int idx = st.kesimo(1, 1, n, p[i]);
        res_st[i] = x[idx];
        st.remove(1, 1, n, idx);
    }
    int res_li[200005];
    ods::ListaIngenua li;
    li.build(x, n);
    for(int i = 0; i < n; i++)
        res_li[i] = li.remove(p[i]);
    for(int i = 0; i < n; i++)
        assert(res_st[i] == res_li[i]);
    cout << nombre << " paso" << endl;
}

void test_invariante(const string& nombre){
    ods::SegmentTree st;
    st.n = 5;
    st.build(1, 1, 5);
    for(int i = 0; i < 5; i++){
        assert(st.tree[1] == 5 - i);
        st.remove(1, 1, 5, st.kesimo(1, 1, 5, 1));
    }
    assert(st.tree[1] == 0);
    cout << nombre << " paso" << endl;
}

int main(){
    //caso 1: ejemplo del problema
    int x1[] = {0, 2, 6, 1, 4, 2};
    int p1[] = {3, 1, 3, 1, 1};
    int e1[] = {1, 2, 2, 6, 4};

    //caso 2: eliminar siempre el primero
    int x2[] = {0, 1, 2, 3, 4, 5};
    int p2[] = {1, 1, 1, 1, 1};
    int e2[] = {1, 2, 3, 4, 5};

    //caso 3: eliminar siempre el ultimo
    int x3[] = {0, 1, 2, 3, 4, 5};
    int p3[] = {5, 4, 3, 2, 1};
    int e3[] = {5, 4, 3, 2, 1};

    //caso 4: un solo elemento
    int x4[] = {0, 42};
    int p4[] = {1};
    int e4[] = {42};

    //caso 5: duplicados
    int x5[] = {0, 5, 5, 5, 5, 5};
    int p5[] = {3, 1, 2, 1, 1};
    int e5[] = {5, 5, 5, 5, 5};

    //caso 6: comparacion contra solucion ingenua
    int x6[] = {0, 2, 6, 1, 4, 2};
    int p6[] = {3, 1, 3, 1, 1};

    cout << "Ejecutando los tests con SegmentTree (solucion principal)\n" << endl;

    ejecutar_test(x1, 5, p1, e1, "Caso de ejemplo del problema");
    ejecutar_test(x2, 5, p2, e2, "Caso de eliminar siempre el primero");
    ejecutar_test(x3, 5, p3, e3, "Caso de eliminar siempre el ultimo");
    ejecutar_test(x4, 1, p4, e4, "Caso de un solo elemento");
    ejecutar_test(x5, 5, p5, e5, "Caso de duplicados");
    comparar_con_ingenua(x6, 5, p6, "Caso de comparacion contra solucion ingenua");
    test_invariante("Caso de invariante principal");

    cout << "\nTodos los tests pasaron" << endl;
    return 0;
}