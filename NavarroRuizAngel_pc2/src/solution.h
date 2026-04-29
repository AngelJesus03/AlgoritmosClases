#pragma once
#include<iostream>
using namespace std;

struct Node{  //estructura de nodos
    int x;
    Node* next;
    explicit Node(int x0) : x(x0),next(nullptr){}
};

struct SLList{    //estructura de lista
    Node* head;
    Node* tail;
    int n;

    SLList() : head(nullptr),tail(nullptr),n(0){}

    void add(int x){   //metodos
        Node* u =new Node(x);
        if(n==0) head=tail=u;
        else{ 
            tail->next=u; tail = u; 
        }
        n++;
    }

    int get(int i){
        Node* u =head;
        for (int k=0; k<i;k++) u=u->next;
        return u->x;
    }

    void set(int i, int x){
        Node* u =head;
        for (int k=0; k<i; k++) u=u->next;
        u->x=x;
    }

    int size(){ return n;}
};

//A
void reverseKGroupValues(SLList& list, int k);

//B
Node* reverseKGroupNodes(Node* head, int k);

void printList(SLList& list);
void printNodes(Node* head);