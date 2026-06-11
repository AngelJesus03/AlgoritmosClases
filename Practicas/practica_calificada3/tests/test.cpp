#include <cassert>
#include <iostream>
#include "../include/solution.h"
using namespace std;

void ejecutar_test(int x[],int n,int p[],int esperado[],const string& nombre){
    ods::SegmentTree st;
    st.n=n;
    st.build(1,1,n);
    for(int i=0;i<n;i++){
        int idx=st.kesimo(1,1,n,p[i]);
        assert(x[idx]==esperado[i]);
        st.remove(1,1,n,idx);
    }
    cout<<nombre<<"paso"<<endl;
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

    // Caso 3: eliminar siempre el ultimo
    int x3[] = {0, 1, 2, 3, 4, 5};
    int p3[] = {5, 4, 3, 2, 1};
    int e3[] = {5, 4, 3, 2, 1};

    //caso 4: un solo elemento
    int x4[] = {0, 42};
    int p4[] = {1};
    int e4[] = {42};

    cout<<"Ejecutando los tests con SegmentTree (solucion principal)"<<endl;

    ejecutar_test(x1, 5, p1, e1, "Caso de ejemplo del problema");
    ejecutar_test(x2, 5, p2, e2, "Caso de eliminar siempre el primero");
    ejecutar_test(x3, 5, p3, e3, "Caso de eliminar siempre el ultimo");
    ejecutar_test(x4, 1, p4, e4, "Caso de un solo elemento");

    cout<<"\nTodos los tests pasaron"<<endl;
    return 0;
}