#include "solution.h"

//solucion A
void reverseKGroupValues(SLList& list, int k){
    int n=list.size();
    for(int i=0; i+k<=n; i+=k){
        int left =i;
        int right =i+k-1;
        while (left<right) {
            int tmp=list.get(left);
            list.set(left,list.get(right));
            list.set(right,tmp);
            left++;
            right--;
        }
    }
}

//solucion B
Node* reverseKGroupNodes(Node* head, int k){
    Node* check=head;
    int count=0;
    while(check && count<k){
        check = check->next;
        count++;
    }
    if (count<k) return head;

    Node* prev=nullptr; //invierte redirigiendo punteros
    Node* curr=head;
    for (int i=0;i<k;i++) {
        Node* next =curr->next;
        curr->next =prev;
        prev=curr;
        curr=next;
    }

    head->next = reverseKGroupNodes(curr, k); //conectamos con el resultado del siguiente grupo
    return prev;
}

//imprimir A
void printList(SLList& list){
    for(int i=0;i<list.size();i++){
        cout<<list.get(i);
        if(i<list.size()-1) cout<<" -> ";
    }
    cout<<"\n";
}
//imprimir B
void printNodes(Node* head){
    while(head){
        cout<<head->x;
        if(head->next) cout<< " -> ";
        head=head->next;
    }
    cout<<"\n";
}