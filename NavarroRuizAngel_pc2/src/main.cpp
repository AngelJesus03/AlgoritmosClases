#include "solution.h"

int main() {
    int vals[]={1,2,3,4,5};

    //solucion A
    cout << "A: intercambiar valores\n";

    SLList l1;
    for(int i=0; i<5;i++) l1.add(vals[i]);
    cout <<"Input:  ";printList(l1);
    reverseKGroupValues(l1,2);
    cout <<"k=2 -> "; printList(l1);

    SLList l2;
    for (int i=0; i<5;i++) l2.add(vals[i]);
    cout<<"Input:  ";printList(l2);
    reverseKGroupValues(l2,3);
    cout<<"k=3 -> ";printList(l2);
    cout<<"\n";

    
    //solucion B
    cout << "B: mover nodos reales\n";

    Node* l3=nullptr;
    Node* tail3=nullptr;
    for (int i=0;i<5;i++) {
        Node* u=new Node(vals[i]);
        if (!l3)l3=tail3 =u;
        else { tail3->next=u; tail3=u; }
    }
    cout<<"Input:  "; printNodes(l3);
    l3=reverseKGroupNodes(l3, 2);
    cout<<"k=2 -> "; printNodes(l3);

    Node* l4 =nullptr;
    Node* tail4 =nullptr;
    for(int i=0;i<5; i++){
        Node* u = new Node(vals[i]);
        if(!l4) l4=tail4=u;
        else{tail4->next=u; tail4 = u; }
    }
    cout<<"Input:  "; printNodes(l4);
    l4=reverseKGroupNodes(l4, 3);
    cout << "k=3 -> "; printNodes(l4);

    return 0;
}