#include <iostream>
#include "../include/solution.h"

int main(){
    int n;
    std::cin>>n;

    int x[200005];
    for(int i=1;i<=n;i++){
        std::cin >> x[i];
    }

    int p[200005];
    for(int i=0;i<n;i++){
        std::cin>>p[i];
    }

    ods::ListaIngenua li;
    li.build(x,n);

    for(int i=0;i<n;i++){
        int val=li.remove(p[i]);
        std::cout<<val;
        if(i<n-1){
            std::cout<<" ";
        }
    }
    std::cout<<"\n";
}