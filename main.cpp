#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include <random>

using namespace std;

class NodeTerm
{
public:
    long int m_Coeff;
    int m_Exp;
    NodeTerm *m_pNext;
    NodeTerm *m_pPrev;

public:
    NodeTerm(long int c, int e)
    {
        m_Coeff = c;
        m_Exp = e;
        m_pNext = 0;
        m_pPrev = 0;
    }

    long int calculate(int x)
    {
        return this->m_Coeff*pow(x, this->m_Exp);
    }
};

class Polinomy
{
public:
    NodeTerm *m_pHead;
    NodeTerm *m_pLast;

public:
    Polinomy()
    {
        m_pHead = m_pLast = 0;
    }

    void addTermAtLast(long int coeff, int exp)
    {
        // Implementar una funcion que me permita insertar al final del polinomio
        NodeTerm *aux = new NodeTerm(coeff, exp);
        if (!this->m_pLast)
        {
            this->m_pLast = aux;
            this->m_pHead = this->m_pLast;
        }
        else
        {
            this->m_pLast->m_pNext = aux;
            aux->m_pPrev = this->m_pLast;
            this->m_pLast = aux;
        }
    }

    void sortLinkedList()
    {
        NodeTerm *curr = this->m_pHead, *temp = 0;
        int t, t1;
        if (!this->m_pHead)
        {
            return;
        }
        else
        {
            while (curr != NULL)
            {
                temp = curr->m_pNext;
                while (temp != NULL)
                {
                    if (curr->m_Exp < temp->m_Exp)
                    {
                        t = curr->m_Exp;
                        t1 = curr->m_Coeff;
                        curr->m_Exp = temp->m_Exp;
                        curr->m_Coeff = temp->m_Coeff;
                        temp->m_Coeff = t1;
                        temp->m_Exp = t;
                    }
                    temp = temp->m_pNext;
                }
                curr = curr->m_pNext;
            }
        }
    }

    void addTerm(long int coeff, int exp)
    {
        // Implementar una funcion que inserte un nuevo termino en el polinomio de manera ordenanda (el mayor grado va a la izquierda o en la cabeza).
        // Si se tienen dos terminos con el mismo grado, estos se combinan por medio de la adición.
        NodeTerm *aux = new NodeTerm(coeff, exp);
        if(!this->m_pHead){
            this->m_pHead = aux;
            this->m_pLast = this->m_pHead;
        } else {
            aux->m_pNext = this->m_pHead;
            this->m_pHead->m_pPrev = aux;
            this->m_pHead = aux;
        }
        sortLinkedList();
        aux = this->m_pHead;
        NodeTerm *temp = aux;
        while(aux->m_pNext){
            temp = aux->m_pNext;
            if(aux->m_Exp == temp->m_Exp){
                aux->m_Coeff += temp->m_Coeff;
                if(temp->m_pNext){
                    aux->m_pNext = temp->m_pNext;
                    temp->m_pNext->m_pPrev = aux;
                    
                }
            }
            aux = aux->m_pNext;
        }
    }

    long int calculate(int x)
    {
        // Implementar método que calcula el valor final del polinomio si reemplazamos la variable independiente X.
        NodeTerm *temp = this->m_pHead;
        long int resp = 0;
        while(temp){
            resp += temp->calculate(x);
            temp = temp->m_pNext;
        }
        return resp;
    }

    Polinomy operate(Polinomy p2)
    {
        // Implementar un método que opera sobre dos polinomios y me genera uno nuevo.
        Polinomy p;
        NodeTerm *temp = this->m_pHead;
        while(temp){
            p.addTermAtLast(temp->m_Coeff, temp->m_Exp);
            temp = temp->m_pNext;
        }
        temp = p2.m_pHead;
        while(temp){
            p.addTermAtLast(temp->m_Coeff, temp->m_Exp);
            temp = temp->m_pNext;
        }
        p.addTerm(0,0);
        return p;
    }

    void print()
    {
        NodeTerm *tmp = m_pHead;
        while (tmp)
        {
            cout << tmp->m_Coeff << "X^" << tmp->m_Exp << " ";
            tmp = tmp->m_pNext;
        }
        cout << endl;
    }
};

int main()
{
    Polinomy x;
    x.addTermAtLast(5, 4);
    x.addTermAtLast(7, 2);
    x.addTermAtLast(3, 1);

    x.print();
    cout << '\n';
    Polinomy y;
    y.addTermAtLast(1, 4);
    y.addTermAtLast(1, 2);
    y.addTermAtLast(1, 1);
    y.print();
    cout << '\n';
    Polinomy a = x.operate(y);

    a.print();

    cout << "Resultado: " << a.calculate(2) << '\n';






    return 0;
}
