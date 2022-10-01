#include "iostream"
#include "string"
#include <stdio.h>

using namespace std;

struct node{
    int coef;
    int grado;
    node*next;
};
struct polinomio{
    node*head=NULL;
    void insert(int coef, int grado){
        node* new__node=new node();
        new__node-> coef = coef;
        new__node-> grado= grado;
    }
};

void print(){
    node * x = this->  head;
    while(x!=NULL){
        cout<<x->coef<<"x"<<x->grado;
        x=x->next;
    }
    cout<<"";
}

add(coef(coef,grado)
