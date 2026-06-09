#include <iostream>
#include "../include/solution.h"

int main(){
    int n;
    std::cin>>n;

    int x[200005];
    for(int i=1;i<=n;i++){
        std::cin>>x[i];
    }

    int p[200005];
    for(int i=0;i<n;i++){
        std::cin>>p[i];
    }

    ods::SegmentTree st;
    st.n=n;
    st.build(1,1,n);

    for(int i=0;i<n;i++){
        int idx=st.kesimo(1, 1, n, p[i]);
        std::cout<<x[idx];
        if(i<n-1){
            std::cout<< " ";
        }
        st.remove(1, 1, n, idx);
    }
    std::cout<<"\n";
}