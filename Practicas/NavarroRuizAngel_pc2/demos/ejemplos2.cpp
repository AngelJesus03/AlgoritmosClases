#include "../include/solution.h"

int main(){
    cout<<"===EJEMPLO EN VIVO===\n";
    int vals[] ={100,890,3,1,4,3,6,1912};
    Node* l1= nullptr;
    Node* tail1=nullptr;
    for(int i=0;i<8;i++){
        Node* u = new Node(vals[i]);
        if(!l1) l1=tail1=u;
        else { tail1->next=u; tail1=u;}
    }
    cout<<"Input EJEMPLO:  "; printNodes(l1);
    l1=reverseKGroupNodes(l1,4);
    cout<<"k=4  -> "; printNodes(l1);
    return 0;
}