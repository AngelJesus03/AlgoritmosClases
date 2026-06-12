#include <iostream>
#include "../include/solution.h"
using namespace std;

void ejecutar_ejemplo(int x[], int n, int p[], const string& nombre){
    cout << nombre <<endl;
    cout << "Input:  ";
    for(int i = 1; i <= n; i++) cout << x[i] << " ";
    cout << endl;
    cout << "Posiciones: ";
    for(int i = 0; i < n; i++) cout << p[i] << " ";
    cout << endl;

    ods::SegmentTree st;
    st.n = n;
    st.build(1, 1, n);

    cout << "Output: ";
    for(int i = 0; i < n; i++){
        int idx = st.kesimo(1, 1, n, p[i]);
        cout << x[idx];
        if(i < n-1) cout << " ";
        st.remove(1, 1, n, idx);
    }
    cout << "\n\n";
}

int main(){
    //ejemplo 1: caso del juez
    int x1[] = {0, 2, 6, 1, 4, 2};
    int p1[] = {3, 1, 3, 1, 1};

    //ejemplo 2: eliminar siempre el ultimo
    int x2[] = {0, 10, 20, 30, 40, 50};
    int p2[] = {5, 4, 3, 2, 1};

    //ejemplo 3: eliminar siempre el primero
    int x3[] = {0, 7, 3, 9, 1, 5};
    int p3[] = {1, 1, 1, 1, 1};

    //ejemplo 4: eliminar del medio
    int x4[] = {0, 1, 2, 3, 4, 5, 6};
    int p4[] = {3, 3, 2, 2, 1, 1};

    ejecutar_ejemplo(x1, 5, p1, "Caso del juez");
    ejecutar_ejemplo(x2, 5, p2, "Eliminar siempre el ultimo");
    ejecutar_ejemplo(x3, 5, p3, "Eliminar siempre el primero");
    ejecutar_ejemplo(x4, 6, p4, "Eliminar del medio");

    return 0;
}