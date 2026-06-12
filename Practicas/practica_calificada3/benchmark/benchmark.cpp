#include <iostream>
#include <chrono>
#include <iomanip>
#include "../include/solution.h"
using namespace std;
using namespace chrono;

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
        << setw(30) << "ListaIngenua O(n^2) ms"
        << setw(30) << "SegmentTree O(n log n) ms" << "\n";
    cout << string(72, '-') << "\n";

    for (int n : tamanios) {
        //genera valores y posiciones
        int x[200005];
        int p[200005];
        for(int i = 1; i <= n; i++) x[i] = i;
        for(int i = 0; i < n; i++) p[i] = 1; //siempre elimina el primero

        double msIngenuo = medir([&]() {
            ods::ListaIngenua li;
            li.build(x, n);
            for(int i = 0; i < n; i++)
                li.remove(p[i]);
        }, REP);

        double msSegTree = medir([&]() {
            ods::SegmentTree st;
            st.n = n;
            st.build(1, 1, n);
            for(int i = 0; i < n; i++){
                int idx = st.kesimo(1, 1, n, p[i]);
                st.remove(1, 1, n, idx);
            }
        }, REP);

        cout << setw(12) << n
            << setw(30) << msIngenuo
            << setw(30) << msSegTree << "\n";
    }

    return 0;
}