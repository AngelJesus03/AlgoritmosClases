#include "../include/solution.h"
namespace ods {

void SegmentTree::build(int node,int start,int end){ //construye el arbol
    if(start==end){
        tree[node] =1; //hoja
    } 
    else {
        int mid =(start + end)/2;
        build(2*node, start, mid);
        build(2*node +1, mid +1, end);
        tree[node]= tree[2*node] +tree[2*node +1]; //suma de elementos
    }
}

void SegmentTree::remove(int node,int start,int end,int idx){ //elimina el elemento y actualiza
    if(start==end){
        tree[node] =0;
    }
    else{
        int mid=(start+end)/2;
        if(idx<= mid){  //mitad izquierda
            remove(2*node, start, mid, idx);
        }
        else{        //mitad derecha
            remove(2*node+1, mid+1, end, idx);
        }
        tree[node]= tree[2*node] + tree[2*node+1];   //actualizar contador
    }
}

int SegmentTree::kesimo(int node,int start,int end,int k){ //retorna el indice
    if(start ==end){
        return start;
    }
    int mid= (start+end)/2;
    if(tree[2*node] >= k){
        return kesimo(2*node, start, mid, k);
    }
    else{
        return kesimo(2*node + 1,mid +1, end, k -tree[2*node]);
    }
}
} // namespace ods